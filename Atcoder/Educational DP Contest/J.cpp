#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,a;
double dp[301][301][301];
double solve(int x,int y,int z){
    if(x==0 && y==0 && z==0)return 0;
    if(!(dp[x][y][z]<-1))return dp[x][y][z];
    dp[x][y][z]=0;
    if(z>0)dp[x][y][z]+=(double)z/n*(1+solve(x,y+1,z-1));
    if(y>0)dp[x][y][z]+=(double)y/n*(1+solve(x+1,y-1,z));
    if(x>0)dp[x][y][z]+=(double)x/n*(1+solve(x-1,y,z));
    dp[x][y][z]+=(double)(n-(x+y+z))/n;
    dp[x][y][z]/=(double)(1-(double)(n-(x+y+z))/n);
    return dp[x][y][z];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int con[4]={0,0,0,0};
    for(int i=0;i<n;i++){
        cin >> a;
        con[a]++;
    }
    for(int i=0;i<=300;i++){
        for(int j=0;j<=300;j++){
            for(int k=0;k<=300;k++){
                dp[i][j][k]=-1e9;
            }
        }
    }
    cout << fixed << setprecision(12) << solve(con[1],con[2],con[3]) << '\n';
}