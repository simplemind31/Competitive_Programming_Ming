#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
string s,t;
int n,m,dp[3001][3001],pad[3001][3001];
int main(){
    cin >> s >> t;
    n=s.size();
    m=t.size();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                pad[i][j]=10000*(i-1)+(j-1);
            }else if(dp[i-1][j]>dp[i][j-1]){
                dp[i][j]=dp[i-1][j];
                pad[i][j]=10000*(i-1)+j;
            }else{
                dp[i][j]=dp[i][j-1];
                pad[i][j]=10000*i+(j-1);
            }
        }
    }
    string res;
    while(n>0 && m>0){
        if(s[n-1]==t[m-1])res.push_back(s[n-1]);
        int x=pad[n][m];
        n=x/10000;
        m=x%10000;
    }
    reverse(res.begin(),res.end());
    cout << res;
}