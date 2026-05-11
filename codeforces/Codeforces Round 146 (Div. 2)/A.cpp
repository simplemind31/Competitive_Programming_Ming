#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> s;
    set<char> c(s.begin(),s.end());
    cout << ((c.size()&1)?"IGNORE HIM!":"CHAT WITH HER!");
}