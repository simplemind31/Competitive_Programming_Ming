#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m;
ll k,grid[20][20],res;
unordered_map<ll,int> pos[20];
void solve(int x,int y,int pasos,bool derecha,ll valor){
    if(y>=m || y<0 || x>=n || x<0 || pasos==0)return;
    valor^=grid[x][y];
    if(pasos==1){
        if(derecha)pos[x][valor]++;
        else res+=pos[x][k^valor^grid[x][y]];
    }
    if(derecha){
        solve(x+1,y,pasos-1,derecha,valor);
        solve(x,y+1,pasos-1,derecha,valor);
    }else{
        solve(x-1,y,pasos-1,derecha,valor);
        solve(x,y-1,pasos-1,derecha,valor);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin >> grid[i][j];
    ll tot=n+m-1,fi=tot/2,se=tot-fi;
    solve(0,0,fi+1,true,0);
    solve(n-1,m-1,se,false,0);
    cout << res;
}