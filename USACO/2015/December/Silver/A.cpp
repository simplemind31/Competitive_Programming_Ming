#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool light[102][102];
int mat[102][102],visited[102][102],n,m,a,b,c,d,con;
vector<pair<int,int>> swit[102][102];
void fill(int x,int y){
    if(visited[x][y] || !light[x][y])return;
    visited[x][y]=true;
    for(auto u:swit[x][y]){
        if(!light[u.first][u.second])con++;
        light[u.first][u.second]=true;
    }
    fill(x-1,y);
    fill(x+1,y);
    fill(x,y-1);
    fill(x,y+1);
    for(auto u:swit[x][y]){
        if(visited[u.first-1][u.second] || visited[u.first+1][u.second] || visited[u.first][u.second-1] || visited[u.first][u.second+1])fill(u.first,u.second);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("lightson.in","r",stdin);
    freopen("lightson.out","w",stdout);
    cin >> n >> m;
    while(m--){
        cin >> a >> b >> c >> d;
        swit[a][b].push_back({c,d});
    }
    con++;
    light[1][1]=true;
    fill(1,1);
    cout << con;
}