#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
#define MOD 1000000007
using namespace std;
typedef long long ll;
char c;
int n,m,k;
int bigmod(int b,int e){
    if(b==0)return 0;
    int p=1;
    for(;e;e>>=1,b=1ll*b*b%MOD)if(e&1)p=1ll*p*b%MOD;
    return p;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("poetry.in","r",stdin);
    freopen("poetry.out","w",stdout);
    cin >> n >> m >> k;//n word, m lines, k syllable
    int dp[k+1][n+1],sum[k+1],con[26],suma[n+1];
    //dp number of ways to get i syllables and ends with word j
    pair<int,int> word[n+1];
    memset(sum,0,sizeof(sum));
    memset(suma,0,sizeof(suma));
    memset(dp,0,sizeof(dp));
    memset(con,0,sizeof(con));
    for(int i=1;i<=n;i++)cin >> word[i].first >> word[i].second;
    dp[0][0]=sum[0]=1;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(i-word[j].first>=0)dp[i][j]=(dp[i][j]+sum[i-word[j].first])%MOD;
            sum[i]=(sum[i]+dp[i][j])%MOD;
        }
    }
    for(int i=1;i<=n;i++)suma[word[i].second]=(suma[word[i].second]+dp[k][i])%MOD;
    while(m--){
        cin >> c;
        con[c-'A']++;
    }
    int res=1;
    for(int i=0;i<26;i++){
        if(con[i]==0)continue;
        int tempsuma=0;
        for(int j=1;j<=n;j++){
            // si A se lleva el grupo j, entonces 
            // pow(suma[j],con[i])
            tempsuma=(tempsuma+bigmod(suma[j],con[i]))%MOD;
        }
        res=1ll*res*tempsuma%MOD;
    }
    cout << res;
}