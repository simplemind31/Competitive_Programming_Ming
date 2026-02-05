// Cookies — O(N^2 * (log N + K log K)) practical implementation
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    if (!(cin >> N >> K)) return 0;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    // Precompute total frequency/multiset of outside elements initially (for l=0)
    ll best = 0; // we allow not opening -> 0

    // For each l, we'll expand r and maintain:
    // outside_rest: multiset of elements currently outside (not in [l..r])
    // outsideKlarge: multiset containing up to K largest elements from outside
    // inside_rest: multiset of inside elements that are not in the K smallest
    // insideKsmall: multiset containing up to K smallest elements from inside
    for (int l = 0; l < N; ++l) {
        // initialize outside as all elements
        multiset<int> outside_rest, outsideKlarge;
        multiset<int> inside_rest, insideKsmall;
        ll outsideKsum = 0, insideKsum = 0;
        for (int i = 0; i < N; ++i) outside_rest.insert(A[i]);

        ll curSum = 0; // sum of current subarray [l..r]
        for (int r = l; r < N; ++r) {
            // move A[r] from outside to inside
            // remove one occurrence from outside sets
            auto it_out_large = outsideKlarge.find(A[r]);
            if (it_out_large != outsideKlarge.end()) {
                outsideKsum -= A[r];
                outsideKlarge.erase(it_out_large);
                // refill outsideKlarge from outside_rest largest if possible
                if (!outside_rest.empty()) {
                    auto it = prev(outside_rest.end());
                    int val = *it;
                    outside_rest.erase(it);
                    outsideKlarge.insert(val);
                    outsideKsum += val;
                }
            } else {
                // it must be in outside_rest
                auto it = outside_rest.find(A[r]);
                if (it != outside_rest.end()) outside_rest.erase(it);
                else {
                    // rare but for correctness: if not found in outsideKlarge nor outside_rest,
                    // it might have been moved earlier; skip.
                }
            }

            // add A[r] to inside; we want insideKsmall to contain up to K smallest inside elements
            if ((int)insideKsmall.size() < K) {
                insideKsmall.insert(A[r]);
                insideKsum += A[r];
            } else {
                if (!insideKsmall.empty() && A[r] < *prev(insideKsmall.end())) {
                    // replace the largest in insideKsmall with new smaller
                    int largest = *prev(insideKsmall.end());
                    insideKsmall.erase(prev(insideKsmall.end()));
                    insideKsum -= largest;
                    insideKsmall.insert(A[r]);
                    insideKsum += A[r];
                    inside_rest.insert(largest);
                } else {
                    inside_rest.insert(A[r]);
                }
            }

            curSum += A[r];

            // Now we must also ensure outsideKlarge contains up to K largest from outside sets:
            // If outsideKlarge size < K and outside_rest nonempty, move largest from outside_rest to outsideKlarge.
            while ((int)outsideKlarge.size() < K && !outside_rest.empty()) {
                auto it = prev(outside_rest.end());
                int val = *it;
                outside_rest.erase(it);
                outsideKlarge.insert(val);
                outsideKsum += val;
            }

            // Prepare vectors of up to K smallest inside and up to K largest outside
            vector<int> insideVec;
            insideVec.reserve(insideKsmall.size());
            for (int v : insideKsmall) insideVec.push_back(v);
            // insideVec already sorted ascending because multiset iterates ascending

            vector<int> outsideVec;
            outsideVec.reserve(outsideKlarge.size());
            // we want descending order of outsideVec (largest first)
            for (auto it = outsideKlarge.rbegin(); it != outsideKlarge.rend(); ++it) outsideVec.push_back(*it);

            int maxT = min({K, (int)insideVec.size(), (int)outsideVec.size()});
            if (maxT == 0) {
                // no beneficial swap possible
                best = max(best, curSum);
                continue;
            }

            // Prefix sums
            vector<ll> prefIn(maxT+1, 0), prefOut(maxT+1, 0);
            for (int t = 1; t <= maxT; ++t) {
                prefIn[t] = prefIn[t-1] + insideVec[t-1];   // t-th smallest inside
                prefOut[t] = prefOut[t-1] + outsideVec[t-1]; // t-th largest outside
            }

            ll curBestForThis = curSum; // t=0
            for (int t = 1; t <= maxT; ++t) {
                ll gain = prefOut[t] - prefIn[t];
                if (gain > 0) curBestForThis = max(curBestForThis, curSum + gain);
            }
            best = max(best, curBestForThis);
        } // end r loop
    } // end l loop

    cout << best << "\n";
    return 0;
}
