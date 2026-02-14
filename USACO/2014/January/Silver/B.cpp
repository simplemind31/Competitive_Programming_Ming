#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool port[502][502];
int mat[502][502],visited[502][502];
char c;
int n,m,k,posx,posy,con,maxi;
void fill(int x,int y){
    if(visited[x][y])return;
    visited[x][y]=true;
    if(port[x][y])con--;
    if(abs(mat[x-1][y]-mat[x][y])<=maxi)fill(x-1,y);
    if(abs(mat[x+1][y]-mat[x][y])<=maxi)fill(x+1,y);
    if(abs(mat[x][y-1]-mat[x][y])<=maxi)fill(x,y-1);
    if(abs(mat[x][y+1]-mat[x][y])<=maxi)fill(x,y+1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("ccski.in","r",stdin);
    freopen("ccski.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++)mat[i][j]=-1e9;
    }
    vector<pair<pair<int,int>,pair<int,int>>> ord;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> mat[i][j];
            ord.push_back({{abs(mat[i][j]-mat[i-1][j]),0},{i,j}});
            ord.push_back({{abs(mat[i][j]-mat[i][j-1]),1},{i,j}});
        }
    }
    // 0 arriba 1 izquierda
    sort(ord.begin(),ord.end());
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> port[i][j];
            con+=port[i][j];
            if(port[i][j]){
                posx=i;
                posy=j;
            }
        }
    }
    visited[posx][posy]=true;
    con--;
    for(auto u:ord){
        maxi=u.first.first;
        pair<int,int> now=u.second;
        pair<int,int> adja=now;
        if(u.first.second)adja.second--;
        else adja.first--;
        if(visited[adja.first][adja.second]){
            fill(now.first,now.second);
        }
        if(visited[now.first][now.second]){
            fill(adja.first,adja.second);
        }
        if(con==0)break;
    }
    cout << maxi;
}