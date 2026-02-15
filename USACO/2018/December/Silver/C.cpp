#include <bits/stdc++.h>
using namespace std;
int n,k,visited[100];
char mat[100][10];
int fill(int x,int y,char color){
    if(x<0 || y<0 || y>9 || x>=n)return 0;
    if(visited[x]&(1<<y) || mat[x][y]!=color)return 0;
    visited[x]|=1<<y;
    return 1+fill(x-1,y,color)+fill(x+1,y,color)+fill(x,y-1,color)+fill(x,y+1,color);
}
void mark0(int x,int y,char color){
    if(x<0 || y<0 || y>9 || x>=n)return;
    if(mat[x][y]!=color)return;
    mat[x][y]='0';
    mark0(x-1,y,color);
    mark0(x+1,y,color);
    mark0(x,y-1,color);
    mark0(x,y+1,color);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("mooyomooyo.in","r",stdin);
    freopen("mooyomooyo.out","w",stdout);
    cin >> n >> k;
    for(int i=0;i<n;i++)for(int j=0;j<10;j++)cin >> mat[i][j];
    vector<pair<int,int>> posic={{0,0}};
    while(!posic.empty()){
        posic.clear();
        for(int i=0;i<n;i++)visited[i]=0;
        for(int i=0;i<n;i++)for(int j=0;j<10;j++)if(mat[i][j]!='0' && fill(i,j,mat[i][j])>=k)posic.push_back({i,j});
        for(auto u:posic)mark0(u.first,u.second,mat[u.first][u.second]);
        for(int j=0;j<10;j++){
            int last=n-1;
            for(int i=n-1;i>=0;i--)if(mat[i][j]!='0')mat[last--][j]=mat[i][j];
            while(last>=0)mat[last--][j]='0';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++)cout << mat[i][j];
        cout << '\n';
    }
}