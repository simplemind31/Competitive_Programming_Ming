#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
using namespace std;
int t,x;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> x >> s;
        int pos=0;
        string c="";
        while(s.size()<=x+10){
            pos++;
            c=s.substr(pos,s.size()-pos);
            for(int i=0;i<s[pos-1]-'0'-1;i++)s.append(c);
            if(pos==x)break;
            //cout << s << ' ' << c << '\n';
        }
        int tamback=s.size()-pos,tamfront=pos;
        while(pos++<x){
            tamfront++;
            tamback--;
            tamback=1ll*tamback*(s[pos-1]-'0')%MOD;
        }
        cout << (tamfront+tamback)%MOD << '\n';
    }
}