#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,D,res;
vector<vector<char>> mat;
vector<vector<ll>> dist,dp;
template<typename T>
vector<T> rotate45(vector<T> x){
    ll tam=x.size();
    vector<T> res(2*tam-1,T(2*tam-1));
    for(ll i=0;i<tam;i++){
        for(ll j=0;j<tam;j++){
            res[i+j][j-i+tam-1]=x[i][j];
        }
    }
    return res;
}
queue<pair<ll,ll>> bfs;
void expand(ll nowx,ll nowy,ll nex,ll ney){
    if(mat[nex][ney]=='#' || dist[nex][ney]!=1e9)return;
    ll nuedist=dist[nowx][nowy]+1;
    if(nuedist<=dp[nex][ney]*D){
        dist[nex][ney]=nuedist;
        bfs.push({nex,ney});
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> D;
    mat.assign(n,vector<char>(n));
    dist.assign(n,vector<ll>(n,1e9));
    dp.assign(n,vector<ll>(n,1e9));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin >> mat[i][j];
            if(mat[i][j]=='S'){
                dist[i][j]=0;
                bfs.push({i,j});
            }
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(mat[i][j]=='#')dp[i][j]=0;
            else{
                if(i && j)dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
                else if(i)dp[i][j]=dp[i-1][j]+1;
                else dp[i][j-1]+1;
            }
        }
    }
    for(ll i=n-1;i>=0;i--){
        for(ll j=n-1;j>=0;j--){
            if(mat[i][j]=='#')dp[i][j]=0;
            else{
                if(i+1<n && j+1<n)dp[i][j]=min(min(dp[i+1][j],dp[i][j+1])+1,dp[i][j]);
                else if(i+1<n)dp[i][j]=min(dp[i-1][j]+1,dp[i][j]);
                else dp[i][j]=min(dp[i-1][j]+1,dp[i][j]);
            }
        }
    }
    while(!bfs.empty()){
        pair<ll,ll> top=bfs.front();
        bfs.pop();
        if(dist[top.first][top.second]/D>=dp[top.first][top.second])continue;
        expand(top.first,top.second,top.first+1,top.second);
        expand(top.first,top.second,top.first-1,top.second);
        expand(top.first,top.second,top.first,top.second+1);
        expand(top.first,top.second,top.first,top.second-1);
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(dist[i][j]==1e9)dist[i][j]=-1;
            if(dp[i][j]*D==dist[i][j])dist[i][j]--;
        }
    }
    vector<vector<char>> ro=rotate45(mat);
    vector<vector<ll>> x=rotate45(dist);
    ll m=ro.size();
    vector psum(m,vector<ll>(m));
    for(ll i=0;i<m;i++){
        for(ll j=0;j<m;j++){
            if(!((i+j)&1))continue;
            if(x[i][j]==-1)continue;
            ll val=x[i][j]/D;
            // desde i-val,j-val al i+val,j+val
            psum[max(i-val,0ll)][max(j-val,0ll)]++;
            if(i+val+1<m)psum[i+val+1][max(j-val,0ll)]--;
            if(j+val+1<m)psum[max(i-val,0ll)][j+val+1]--;
            if(i+val+1<m && j+val+1<m)psum[i+val+1][j+val+1]++;
        }
    }
    for(ll i=0;i<m;i++){
        for(ll j=0;j<m;j++){
            if(j)psum[i][j]+=psum[i][j-1];
            if(i)psum[i][j]+=psum[i-1][j];
            if(i&&j)psum[i][j]-=psum[i-1][j-1];
            if(psum[i][j] && ((i+j)&1))ro[i][j]='X';
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(mat[i][j]=='#')continue;
            mat[i][j]=ro[i+j][j-i+n-1];
            if(mat[i][j]=='X')res++;
        }
    }
    cout << res;
}