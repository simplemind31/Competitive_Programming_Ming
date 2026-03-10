#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,c,num;
bool dp[501][501][501],posi[501];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> c;
    dp[0][0][0]=true;
    for(int i=1;i<=n;i++){
        cin >> num;
        for(int j=0;j<=c;j++){
            for(int k=0;k<=c;k++){
                dp[i][j][k]|=dp[i-1][j][k];
                if(j-num>=0){
                    dp[i][j][k]|=dp[i-1][j-num][k];
                    if(k-num>=0)dp[i][j][k]|=dp[i-1][j-num][k-num];
                }
            }
        }
    }
    vector<int> res;
    for(int i=0;i<=c;i++){
        if(dp[n][c][i])res.push_back(i);
        posi[i]=dp[n][c][i];
    }
    cout << res.size() << '\n';
    for(auto u:res)cout << u << ' ';
}