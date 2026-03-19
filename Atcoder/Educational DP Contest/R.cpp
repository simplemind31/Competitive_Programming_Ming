#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int dp[10001][100],k,n,res,obli;
// digito i con modulo j
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st >> k;
    n=st.size();
    dp[n][0]=1;
    for(int i=n;i>0;i--){
        for(int j=0;j<k;j++){
            for(int l=0;l<10;l++){
                // el digito i-1 es l
                // (l+x)%k=j
                dp[i-1][(j+l)%k]=(dp[i-1][(j+l)%k]+dp[i][j])%MOD;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<st[i]-'0';j++){
            // para que sea 0 (obli+j+x)%k=0
            res=(res+dp[i+1][(2*k-obli-j)%k])%MOD;
        }
        obli=(obli+st[i]-'0')%k;
    }
    if(obli==0)res++;
    res=(res-1+MOD)%MOD;
    cout << res;
}