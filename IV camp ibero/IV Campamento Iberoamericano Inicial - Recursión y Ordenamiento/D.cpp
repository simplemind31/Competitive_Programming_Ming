#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cost[3][3],n;
ll dp[41][3][3];
// para mover el iemismo de plato j al k
ll solve(int can,int pos,int dest){
    if(dp[can][pos][dest]!=1e18){
        return dp[can][pos][dest];
    }
    //ir directo al dest:
    int libre=3-pos-dest;
    dp[can][pos][dest]=min(dp[can][pos][dest],solve(can-1,pos,libre)+cost[pos][dest]+solve(can-1,libre,dest));
    // usar un medio
    dp[can][pos][dest]=min(dp[can][pos][dest],solve(can-1,pos,dest)+cost[pos][libre]+solve(can-1,dest,pos)+cost[libre][dest]+solve(can-1,pos,dest));
    return dp[can][pos][dest];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> cost[i][j];
        }
    }
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                dp[i][j][k]=1e18;
            }
        }
    }
    for(int j=0;j<3;j++){
        for(int k=0;k<3;k++){
            dp[0][j][k]=0;
        }
    }
    cout << solve(n,0,2);
}