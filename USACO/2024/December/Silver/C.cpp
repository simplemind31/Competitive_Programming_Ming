#include <bits/stdc++.h>
using namespace std;
int n,canlibre,q;
pair<int,int> pad[1004][1004];
char mat[1004][1004];
bitset<1004> libre[1004];
void liberar(int x,int y){
    if(libre[x][y])return;
    libre[x][y]=true;
    canlibre++;
    if(x-1>=0){
        if(mat[x-1][y]==0 || mat[x-1][y]=='D')liberar(x-1,y);
    }
    if(x+1<n+4){
        if(mat[x+1][y]==0 || mat[x+1][y]=='U')liberar(x+1,y);
    }
    if(y-1>=0){
        if(mat[x][y-1]==0 || mat[x][y-1]=='R')liberar(x,y-1);
    }
    if(y+1<n+4){
        if(mat[x][y+1]==0 || mat[x][y+1]=='L')liberar(x,y+1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    vector<pair<pair<int,int>,char>> query(q);
    for(int i=0;i<q;i++){
        cin >> query[i].first.first >> query[i].first.second >> query[i].second;
        query[i].first.first++;
        query[i].first.second++;
        mat[query[i].first.first][query[i].first.second]=query[i].second;
    }
    for(int i=0;i<n+4;i++){
        liberar(i,0);
        liberar(i,n+3);
        liberar(0,i);
        liberar(n+3,i);
    }
    vector<int> res;
    for(int i=q-1;i>=0;i--){
        res.push_back((n+4)*(n+4)-canlibre);
        mat[query[i].first.first][query[i].first.second]=0;
        if(libre[query[i].first.first][query[i].first.second-1] || libre[query[i].first.first][query[i].first.second+1] || libre[query[i].first.first-1][query[i].first.second] || libre[query[i].first.first+1][query[i].first.second])liberar(query[i].first.first,query[i].first.second);
    }
    reverse(res.begin(),res.end());
    for(auto u:res)cout << u << '\n';
}