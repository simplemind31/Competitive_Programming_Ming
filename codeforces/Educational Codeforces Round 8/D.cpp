#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef long double ld;
const ld PI=acos(-1.0);
int m,d,n;
string a,b;
ll solve(string x,bool inclu){
    ll dp[n][m][2];
    // cantidad de d-magic que:
    // position i
    // it has remainder j
    // k=0->not tight,l=1->tight
    memset(dp,0,sizeof(dp));
    //i&1 pueden ser d
    for(int i=0;i<x[0]-'0';i++){
        // skip d
        if(i==d)continue;
        dp[0][i%m][0]=dp[0][i%m][0]+1;
    }
    if(x[0]-'0'!=d)dp[0][(x[0]-'0')%m][1]=dp[0][(x[0]-'0')%m][1]+1;
    ll actremain=(x[0]-'0')%m;
    for(int i=1;i<n;i++){
        // seguimos tight
        if(i&1){
            // solo usar d
            if(x[i]-'0'==d)dp[i][(actremain*10+d)%m][1]=(dp[i][(actremain*10+d)%m][1]+dp[i-1][actremain][1])%MOD;
            if(d<x[i]-'0')dp[i][(actremain*10+d)%m][0]=(dp[i][(actremain*10+d)%m][0]+dp[i-1][actremain][1])%MOD;
            for(int k=0;k<m;k++)dp[i][(k*10+d)%m][0]=(dp[i][(k*10+d)%m][0]+dp[i-1][k][0])%MOD;
            actremain=(actremain*10+x[i]-'0')%m;
            continue;
        }
        if(x[i]-'0'!=d)dp[i][(actremain*10+x[i]-'0')%m][1]=(dp[i][(actremain*10+x[i]-'0')%m][1]+dp[i-1][actremain][1])%MOD;
        for(int j=0;j<x[i]-'0';j++){
            // eramos tight, pero ya no
            if(j==d)continue;
            dp[i][(actremain*10+j)%m][0]=(dp[i][(actremain*10+j)%m][0]+dp[i-1][actremain][1])%MOD;
        }
        for(int j=0;j<10;j++){
            // nunca fuimos tight
            if(j==d)continue;
            for(int k=0;k<m;k++)dp[i][(k*10+j)%m][0]=(dp[i][(k*10+j)%m][0]+dp[i-1][k][0])%MOD;
        }
        actremain=(actremain*10+x[i]-'0')%m;
    }
    ll res=dp[n-1][0][0];
    if(inclu)res=(res+dp[n-1][0][1])%MOD;
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> m >> d >> a >> b;
    n=a.size();
    cout << (solve(b,1)-solve(a,0)+MOD)%MOD;
}