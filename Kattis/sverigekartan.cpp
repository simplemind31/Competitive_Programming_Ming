#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool mat[502][502],visited[502][502];
char c;
int n,m,k,posx,posy,con;
void fill(int x,int y){
    if(!mat[x][y] || visited[x][y])return;
    visited[x][y]=true;
    con++;
    fill(x-1,y);
    fill(x+1,y);
    fill(x,y-1);
    fill(x,y+1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> c;
            mat[i][j]=c!='.';
            if(c=='S'){
                posx=i;
                posy=j;
            }
        }
    }
    fill(posx,posy);
    cout << con << '\n';
    while(k--){
        cin >> posx >> posy;
        mat[posx][posy]=1;
        if(visited[posx-1][posy] || visited[posx+1][posy] || visited[posx][posy-1] || visited[posx][posy+1])fill(posx,posy);
        cout << con << '\n';
    }
}