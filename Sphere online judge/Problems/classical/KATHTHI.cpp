#include <bits/stdc++.h>
using namespace std;
int t,n,m;
deque<pair<int,int>> cola;
vector<vector<int>> dist;
vector<vector<char>> mat;
void solve(int nowx,int nowy,int nex,int ney){
    if(nex<0 ||)
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t >>n >> m;
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
        cola.push_front({0,0});
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