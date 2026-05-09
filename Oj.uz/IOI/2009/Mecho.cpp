#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,s,mx,my,dx,dy;
char mat[800][800];
ll dist[800][800],nuedist[800][800];
queue<pair<ll,ll>> bfs,bfs2;
void expand(ll nowx,ll nowy,ll nex,ll ney){
    if(nex<0 || nex>=n || ney<0 || ney>=n)return;
    if(mat[nex][ney]=='D' || mat[nex][ney]=='T' || dist[nex][ney]!=1e9)return;
    dist[nex][ney]=dist[nowx][nowy]+1;
    bfs.push({nex,ney});
}
void expand2(ll nowx,ll nowy,ll nex,ll ney){
    if(nex<0 || nex>=n || ney<0 || ney>=n)return;
    if(mat[nex][ney]=='T' || nuedist[nex][ney]!=1e9)return;
    ll nuevadi=nuedist[nowx][nowy]+1;
    //if(nuevadi%s==0)
    if(nuevadi<dist[nex][ney]*s){
        nuedist[nex][ney]=nuevadi;
        bfs2.push({nex,ney});
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> s;
    fill(&dist[0][0],&dist[0][0]+800*800,1e9);
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin >> mat[i][j]; 
            if(mat[i][j]=='H'){
                dist[i][j]=0;
                bfs.push({i,j});
            }else if(mat[i][j]=='M'){
                mx=i;
                my=j;
            }else if(mat[i][j]=='D'){
                dx=i;
                dy=j;
            }
        }
    }
    while(!bfs.empty()){
        pair<ll,ll> top=bfs.front();
        bfs.pop();
        expand(top.first,top.second,top.first+1,top.second);
        expand(top.first,top.second,top.first-1,top.second);
        expand(top.first,top.second,top.first,top.second+1);
        expand(top.first,top.second,top.first,top.second-1);
    }
    /*for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cout << dist[i][j] << ' ';
        }
        cout << endl;
    }*/
    ll l=-1,r=dist[mx][my]-1;
    while(l<r){
        ll mid=(l+r+1)>>1;
        // comi mid segundos
        // puedo ir s bloques por segundo
        fill(&nuedist[0][0],&nuedist[0][0]+800*800,1e9);
        nuedist[mx][my]=mid*s;
        bfs2.push({mx,my});
        while(!bfs2.empty()){
            pair<ll,ll> top=bfs2.front();
            bfs2.pop();
            expand2(top.first,top.second,top.first+1,top.second);
            expand2(top.first,top.second,top.first-1,top.second);
            expand2(top.first,top.second,top.first,top.second+1);
            expand2(top.first,top.second,top.first,top.second-1);
        }
        if(nuedist[dx][dy]==1e9)r=mid-1;
        else l=mid;
    }
    cout << l;
}
/*
T  T  T  T  T  T  T
T  G  G  G  G  G  T 
T 11  G  G  G  G  T 
9 10  X  X  G  G  D 
T  X  X  X  X  G  T 
T  X  X  X  X  X  T 
T  X  H  H  X  X  T 
*/