#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n,m;
char c;
int main(){
    cin >> n >> m;
    int dp[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i][j]=0;
            cin >> c;
            if(c=='#')continue;
            if(!(i||j))dp[i][j]=1;
            if(i)dp[i][j]+=dp[i-1][j];
            if(j)dp[i][j]+=dp[i][j-1];
            dp[i][j]%=MOD;
        }
    }
    cout << dp[n-1][m-1];
}