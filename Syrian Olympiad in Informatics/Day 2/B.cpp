#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

int n, m, q;
string safe_str, password;
vector<ll> cost;

int dist[26][26];

void precompute_distances() {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            int forward = (j - i + 26) % 26;
            int backward = (i - j + 26) % 26;
            dist[i][j] = min(forward, backward);
        }
    }
}

void precompute_costs() {
    cost.assign(n, INF);
    for (int i = 0; i + m <= n; i++) {
        ll sum = 0;
        for (int j = 0; j < m; j++) {
            sum += dist[safe_str[i + j] - 'a'][password[j] - 'a'];
        }
        cost[i] = sum;
    }
}

ll solve_range(int L, int R) {
    int len = R - L + 1;
    if (len < m) return -1;
    
    int t = len / m;
    int max_starts = R - m + 1 - L + 1;
    
    vector<vector<ll>> dp(max_starts + 1, vector<ll>(t + 1, INF));
    dp[0][0] = 0;
    
    for (int i = 1; i <= max_starts; i++) {
        int start_pos = L + i - 1;
        
        for (int j = 0; j <= t; j++) {
            dp[i][j] = dp[i - 1][j];
            
            if (j > 0) {
                if (i >= m) {
                    if (dp[i - m][j - 1] < INF) {
                        ll new_cost = dp[i - m][j - 1] + cost[start_pos];
                        if (new_cost < dp[i][j]) {
                            dp[i][j] = new_cost;
                        }
                    }
                } else if (j == 1) {
                    if (cost[start_pos] < dp[i][j]) {
                        dp[i][j] = cost[start_pos];
                    }
                }
            }
        }
    }
    
    return dp[max_starts][t];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> q;
    cin >> safe_str >> password;
    
    precompute_distances();
    precompute_costs();
    
    // Debug: print costs
    cerr << "Costs: ";
    for (int i = 0; i < n; i++) {
        if (cost[i] < INF) cerr << i << ":" << cost[i] << " ";
    }
    cerr << endl;
    
    while (q--) {
        int L, R;
        cin >> L >> R;
        ll ans = solve_range(L, R);
        cout << (ans >= INF ? -1 : ans) << '\n';
    }
    
    return 0;
}