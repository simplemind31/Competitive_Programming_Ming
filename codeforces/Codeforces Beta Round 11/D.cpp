#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
bool edges[19][19];
ll dp[1<<19][19],res;
int n,m,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        edges[--a][--b]=1;
        edges[b][a]=1;
    }
    for(int mask=0;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            // es posible que first(mask) inicia y termina en i?
            if(mask&(1<<i)){
                if(__builtin_popcount(mask)==1)dp[mask][i]=1;
                else{
                    for(int j=0;j<n;j++){
                        if((mask&(1<<j)) && i!=__builtin_ctz(mask))dp[mask][i]+=dp[mask^(1<<i)][j]*edges[i][j];
                    }
                }
            }
            if(__builtin_popcount(mask)>2 && edges[__builtin_ctz(mask)][i])res+=dp[mask][i];
        }
    }
    cout << res/2;
}