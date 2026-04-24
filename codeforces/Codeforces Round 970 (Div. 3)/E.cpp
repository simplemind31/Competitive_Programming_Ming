#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
const int MAXN=200000;
int n,t;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> st;
        // si n par, solo quitar
        int tot[2][26],now[2][26];
        memset(tot,0,sizeof(tot));
        memset(now,0,sizeof(now));
        for(int i=0;i<n;i++){
            tot[i&1][st[i]-'a']++;
            now[i&1][st[i]-'a']++;
        }
        if(n&1){
            int res=n;
            // tot-now=iz now=de
            for(int i=0;i<n;i++){
                // eliminar i
                int maxipa=0,maxiim=0;
                now[i&1][st[i]-'a']--;
                tot[i&1][st[i]-'a']--;
                for(int j=0;j<26;j++){
                    maxipa=max(maxipa,tot[0][j]-now[0][j]+now[1][j]);
                    maxiim=max(maxiim,tot[1][j]-now[1][j]+now[0][j]);
                }
                tot[i&1][st[i]-'a']++;
                res=min(res,n-maxipa-maxiim);
            }
            cout << res << '\n';
        }else{
            // los pares e impares
            int maxipa=0,maxiim=0;
            for(int i=0;i<26;i++){
                maxipa=max(maxipa,tot[0][i]);
                maxiim=max(maxiim,tot[1][i]);
            }
            cout << n-maxipa-maxiim << '\n';
        }
    }
}