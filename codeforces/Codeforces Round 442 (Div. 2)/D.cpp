#include <bits/stdc++.h>
using namespace std;
int n,m,k,a,b,c,d;
vector<vector<char>> mat;
vector<vector<int>> nextrow,nextcol,prevrow,prevcol,dist;
queue<pair<int,int>> cola;
int findnextrow(int x,int y){
    if(y==m)return y;
    return (y==nextrow[x][y])?y:nextrow[x][y]=findnextrow(x,nextrow[x][y]);
}
int findprevrow(int x,int y){
    if(y==-1)return y;
    return (y==prevrow[x][y])?y:prevrow[x][y]=findprevrow(x,prevrow[x][y]);
}
int findnextcol(int x,int y){
    if(x==n)return x;
    return (x==nextcol[x][y])?x:nextcol[x][y]=findnextcol(nextcol[x][y],y);
}
int findprevcol(int x,int y){
    if(x==-1)return x;
    return (x==prevcol[x][y])?x:prevcol[x][y]=findprevcol(prevcol[x][y],y);
}
bool solve(int nowx,int nowy,int nex,int ney){
    if(nex<0 || nex>=n || ney<0 || ney>=m)return false;
    if(abs(nowx-nex)+abs(nowy-ney)>k)return false;
    if(mat[nex][ney]=='#')return false;
    if(dist[nex][ney]>dist[nowx][nowy]+1){
        dist[nex][ney]=dist[nowx][nowy]+1;
        cola.push({nex,ney});
        nextrow[nex][ney]=ney+1;
        nextcol[nex][ney]=nex+1;
        prevrow[nex][ney]=ney-1;
        prevcol[nex][ney]=nex-1;
        return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    mat.assign(n,vector<char>(m));
    nextrow.assign(n,vector<int>(m));
    prevrow.assign(n,vector<int>(m));
    nextcol.assign(n,vector<int>(m));
    prevcol.assign(n,vector<int>(m));
    dist.assign(n,vector<int>(m,1e9));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
            nextrow[i][j]=j;
            prevrow[i][j]=j;
            nextcol[i][j]=i;
            prevcol[i][j]=i;
        }
    }
    cin >> a >> b >> c >> d;
    dist[--a][--b]=0;
    cola.push({a,b});
    while(!cola.empty()){
        pair<int,int> pos=cola.front();
        cola.pop();
        while(solve(pos.first,pos.second,pos.first,findnextrow(pos.first,pos.second+1)));
        while(solve(pos.first,pos.second,pos.first,findprevrow(pos.first,pos.second-1)));
        while(solve(pos.first,pos.second,findnextcol(pos.first+1,pos.second),pos.second));
        while(solve(pos.first,pos.second,findprevcol(pos.first-1,pos.second),pos.second));
    }
    if(dist[--c][--d]==1e9)dist[c][d]=-1;
    cout << dist[c][d];
}