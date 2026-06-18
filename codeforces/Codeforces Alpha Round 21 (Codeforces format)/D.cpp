#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a,b,c;
ll res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    int mat[n][n],deg[n];
    memset(deg,0,sizeof(deg));
    fill(&mat[0][0],&mat[0][0]+n*n,1e9);
    for(int i=0;i<n;i++)mat[i][i]=0;
    vector<pair<int,int>> edges;
    while(m--){
        cin >> a >> b >> c;
        deg[--a]++;
        deg[--b]++;
        edges.push_back({a,b});
        mat[a][b]=mat[b][a]=min(mat[a][b],c);
        res+=c;
    }
    for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
    vector<int> odd;
    for(int i=0;i<n;i++)if(deg[i]&1)odd.push_back(i);
    for(auto u:edges){
        if(mat[0][u.first]==1e9 && mat[0][u.second]==1e9){
            cout << -1;
            return 0;
        }
    }
    n=odd.size();
    int dp[1<<n];
    fill(dp,dp+(1<<n),1e9);
    dp[0]=0;
    for(int mask=0;mask<(1<<n);mask++){
        if(dp[mask]==1e9)continue;
        for(int i=0;i<n;i++){
            if(mask&(1<<i))continue;
            for(int j=0;j<n;j++){
                if(j==i || mask&(1<<j))continue;
                dp[mask|(1<<i)|(1<<j)]=min(dp[mask|(1<<i)|(1<<j)],dp[mask]+mat[odd[i]][odd[j]]);
            }
        }
    }
    cout << res+dp[(1<<n)-1];

}