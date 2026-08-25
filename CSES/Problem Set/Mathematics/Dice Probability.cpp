#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> a >> b;
    ld dp[n+1][b+1],res=0;
    memset(dp,0,sizeof(dp));
    // dp[i][j]=probabilidad de usar i dices y sacar suma de j
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=b;j++){
            for(int k=1;k<=6;k++){
                if(j-k>=0)dp[i][j]+=dp[i-1][j-k]/6;
            }
        }
    }
    for(int i=a;i<=b;i++)res+=dp[n][i];
    cout << fixed << setprecision(6) << res;
}