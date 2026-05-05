#include <bits/stdc++.h>
using namespace std;
int t,n,m,a,b,c,d;
deque<pair<int,int>> cola;
vector<vector<int>> dist;
vector<vector<char>> mat;
void solve(int nowx,int nowy,int nex,int ney,int val){
    if(nex<0 || nex>=n || ney<0 || ney>=m)return;
    int nd=dist[nowx][nowy]+(val!=mat[nowx][nowy]-'0');
    if(nd<dist[nex][ney]){
        if(val!=mat[nowx][nowy]-'0'){
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
    cin >> n >> m;
    mat.clear();
    mat.assign(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }
    cin >> t;
    while(t--){
        dist.clear();
        dist.assign(n,vector<int>(m,1e9));
        cin >> a >> b >> c >> d;
        dist[--a][--b]=0;
        cola.push_back({a,b});
        while(!cola.empty()){
            pair<int,int> now=cola.front();
            cola.pop_front();
            solve(now.first,now.second,now.first-1,now.second,0);
            solve(now.first,now.second,now.first-1,now.second+1,1);
            solve(now.first,now.second,now.first,now.second+1,2);
            solve(now.first,now.second,now.first+1,now.second+1,3);
            solve(now.first,now.second,now.first+1,now.second,4);
            solve(now.first,now.second,now.first+1,now.second-1,5);
            solve(now.first,now.second,now.first,now.second-1,6);
            solve(now.first,now.second,now.first-1,now.second-1,7);
        }
        cout << dist[--c][--d] << '\n';
    }
}