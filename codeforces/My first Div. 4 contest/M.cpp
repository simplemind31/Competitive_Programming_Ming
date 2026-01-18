#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll cnt = 0, first = 0;
    bool found = false;
    for (ll i = 0; i < n; i++) {
        if (!found && s[i] == '1') first++;
        else if (s[i] == '1' && found) {
            cnt++;
            if (cnt == 2) {
                cout << -1 << endl;
                return;
            }
        } else {
            found = true;
            cnt = 0;
        }
    }
    if (first == 0) {
        cout << -1 << endl;
        return;
    }
    vector<ll> block;
    cnt = 0;
    for (ll i = 0; i < n; i++) {
        if (s[i] == '0') cnt++;
        else {
            if (cnt != 0) block.pb(cnt);
            cnt = 0;
        }
    }
    ll si = block.size();
    if (si == 0) {
        string ans;
        for (ll i = 0; i < first; i++) ans.pb('1');
        for (ll i = first; i < n; i++) ans.pb('0');
        cout << ans << endl;
        return;
    }
    if (block[0] < first) {
        cout << -1 << endl;
        return;
    }
    for (ll x : block) {
        if (x != block[0]) {
            cout << -1 << endl;
            return;
        }
    }
    string ans;
    for (ll i = 0; i < first; i++) ans.pb('1');
    for (ll i = 0; i < si; i++) {
        for (ll j = 0; j <= block[i] - first; j++) ans.pb('0');
        for (ll j = block[i] - first + 1; j < block[i] + 1; j++) ans.pb('1');
    }
    while (ans.size() < n) ans.pb('0');
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll t = 1;
    cin >> t;
    while (t--) solve();
}