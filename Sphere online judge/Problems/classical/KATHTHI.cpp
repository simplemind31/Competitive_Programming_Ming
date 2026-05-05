#include <bits/stdc++.h>
using namespace std;
int t,n,m;
deque<pair<int,int>> cola;
vector<vector<int>> dist;
vector<vector<char>> mat;
void solve(int nowx,int nowy,int nex,int ney){
    if(nex<0 || nex>=n || ney<0 || ney>=m)return;
    int nd=dist[nowx][nowy]+(mat[nowx][nowy]!=mat[nex][ney]);
    if(nd<dist[nex][ney]){
        if(mat[nowx][nowy]!=mat[nex][ney]){
            cola.push_back({nex,ney});
            dist[nex][ney]=dist[nowx][nowy]+1;
        }else{
            cola.push_front({nex,ney});
            dist[nex][ney]=dist[nowx][nowy];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        mat.clear();
        mat.assign(n,vector<char>(m));
        dist.clear();
        dist.assign(n,vector<int>(m,1e9));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> mat[i][j];
            }
        }
        dist[0][0]=0;
        cola.push_back({0,0});
        while(!cola.empty()){
            pair<int,int> now=cola.front();
            cola.pop_front();
            solve(now.first,now.second,now.first-1,now.second);
            solve(now.first,now.second,now.first,now.second-1);
            solve(now.first,now.second,now.first+1,now.second);
            solve(now.first,now.second,now.first,now.second+1);
        }
        cout << dist[n-1][m-1] << '\n';
    }
}