#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> s;
        if(s.size()>10)cout << s[0] << s.size()-2 << s.back();
        else cout << s;
        cout << '\n';
    }
}