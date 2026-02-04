#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
char c;
int n,m,con[26],now[26];
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> s;
    for(int i=0;i<m;i++){
        cin >> c;
        con[c-'a']++;
    }
    int j=0;
    ll can=0;
    for(int i=0;i<n;i++){
        now[s[i]-'a']++;
        while(now[s[i]-'a']>con[s[i]-'a'])now[s[j++]-'a']--;
        can+=i-j+1;
    }
    cout << can;
}