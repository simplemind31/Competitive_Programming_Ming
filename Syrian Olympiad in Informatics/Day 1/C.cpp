// Candy — O(N)
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N, X, Y;
    if (!(cin >> N >> X >> Y)) return 0;
    long long total_minus = 0;
    for (int i = 0; i < N; ++i) {
        long long a; cin >> a;
        total_minus += max(0LL, a - 1);
    }
    long long maxCuts = min(total_minus, X * Y);
    cout << (N + maxCuts) << "\n";
    return 0;
}
