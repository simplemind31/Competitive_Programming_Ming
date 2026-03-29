#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll res;
string x;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> x;
    for(int target=1;target<=9*x.size();target++){
        // digito i, suma, residuo%target, obligado
        ll dp[x.size()+1][target+1][target][2];
        memset(dp,0,sizeof(dp));
        dp[0][0][0][1]=1;
        for(int i=0;i<x.size();i++){
            for(int j=0;j<=target;j++){
                for(int k=0;k<target;k++){
                    for(int l=0;l<=9;l++){
                        if(j+l>target)break;
                        dp[i+1][j+l][(k*10+l)%target][0]+=dp[i][j][k][0];
                        if(l==x[i]-'0')dp[i+1][j+l][(k*10+l)%target][1]+=dp[i][j][k][1];
                        else if(l<x[i]-'0')dp[i+1][j+l][(k*10+l)%target][0]+=dp[i][j][k][1];
                    }
                }
            }
        }
        res+=dp[x.size()][target][0][0]+dp[x.size()][target][0][1];
    }
    cout << res;
}