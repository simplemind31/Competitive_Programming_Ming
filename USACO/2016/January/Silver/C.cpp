#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,posx,posy,con,minix=1e9,miniy=1e9,maxix=-1e9,maxiy=-1e9;
string st;
vector<vector<int>> mat;
vector<vector<bool>> visited;
void fill(int x,int y){
    if(x<=0 || y<=0 || x+1>=mat.size() || y+1>=mat[0].size())return;
    if(visited[x][y] || mat[x][y])return;
    visited[x][y]=true;
    fill(x-1,y);
    fill(x+1,y);
    fill(x,y-1);
    fill(x,y+1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("gates.in","r",stdin);
    freopen("gates.out","w",stdout);
    cin >> n >> st;
    for(int i=0;i<n;i++){
        if(st[i]=='N'){
            //mat[posx][posy+1]=mat[posx][posy+2]=1;
            posy+=2;
        }else if(st[i]=='S'){
            //mat[posx][posy-1]=mat[posx][posy-2]=1;
            posy-=2;
        }else if(st[i]=='E'){
            //mat[posx+1][posy]=mat[posx+2][posy]=1;
            posx+=2;
        }else{
            //mat[posx-1][posy]=mat[posx-2][posy]=1;
            posx-=2;
        }
        minix=min(minix,posx);
        maxix=max(maxix,posx);
        miniy=min(miniy,posy);
        maxiy=max(maxiy,posy);
    }
    posx=50+abs(minix);
    posy=50+abs(miniy);
    //cout << maxix << ' ' << minix << ' ' << maxiy << ' ' << miniy <<'\n';
    mat.assign(maxix-minix+200,vector<int>(maxiy-miniy+200));
    visited.assign(maxix-minix+200,vector<bool>(maxiy-miniy+200));
    for(int i=0;i<n;i++){
        if(st[i]=='N'){
            mat[posx][posy+1]=mat[posx][posy+2]=1;
            posy+=2;
        }else if(st[i]=='S'){
            mat[posx][posy-1]=mat[posx][posy-2]=1;
            posy-=2;
        }else if(st[i]=='E'){
            mat[posx+1][posy]=mat[posx+2][posy]=1;
            posx+=2;
        }else{
            mat[posx-1][posy]=mat[posx-2][posy]=1;
            posx-=2;
        }
    }
    for(int i=0;i<maxiy-miniy+100;i++){
        mat[0][i]=mat[maxix-minix+100-1][i]=1;
    }
    for(int i=0;i<maxix-minix+100;i++){
        mat[i][0]=mat[i][maxiy-miniy+100-1]=1;
    }
    for(int i=0;i<maxix-minix+100;i++){
        for(int j=0;j<maxiy-miniy+100;j++){
            if(visited[i][j] || mat[i][j])continue;
            fill(i,j);
            con++;
        }
    }
    cout << con-1;
}