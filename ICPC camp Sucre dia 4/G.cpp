#include <bits/stdc++.h>
using namespace std;
int n,m,res,ax,ay,bx,by;
char mat[1000][1000];
int dist[1000][1000],pad[1000][1000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
            if(mat[i][j]=='A'){
                ax=i;
                ay=j;
            }else if(mat[i][j]=='B'){
                bx=i;
                by=j;
            }
        }
    }
    queue<pair<int,int>> cola;
    cola.push({bx,by});
    // 0l,1d,2r,3u
    while(!cola.empty()){
        pair<int,int> top=cola.front();
        cola.pop();
        int x=top.first,y=top.second;
        if(mat[x][y]=='#')continue;
        if(x-1>=0){
            if(dist[x-1][y]==0){
                dist[x-1][y]=dist[x][y]+1;
                pad[x-1][y]=1;
                cola.push({x-1,y});
            }
        }
        if(x+1<n){
            if(dist[x+1][y]==0){
                dist[x+1][y]=dist[x][y]+1;
                pad[x+1][y]=3;
                cola.push({x+1,y});
            }
        }
        if(y-1>=0){
            if(dist[x][y-1]==0){
                dist[x][y-1]=dist[x][y]+1;
                pad[x][y-1]=2;
                cola.push({x,y-1});
            }
        }
        if(y+1<m){
            if(dist[x][y+1]==0){
                dist[x][y+1]=dist[x][y]+1;
                pad[x][y+1]=0;
                cola.push({x,y+1});
            }
        }
    }
    if(!dist[ax][ay]){
        cout << "NO";
        return 0;
    }
    cout << "YES\n" << dist[ax][ay] << '\n';
    while(ax!=bx || ay!=by){
        if(pad[ax][ay]==0){
            cout << 'L';
            ay--;
        }else if(pad[ax][ay]==1){
            cout << 'D';
            ax++;
        }else if(pad[ax][ay]==2){
            cout << 'R';
            ay++;
        }else{
            cout << 'U';
            ax--;
        }
    }
}
