#include <bits/stdc++.h>
using namespace std;
int n,grid[500][500],visited[500][500];
int expand(int nowx,int nowy,int nex,int ney,int lim){
    if(ney<0 || nex<0 || nex>=n || ney>=n)return 0;
    if(visited[nex][ney] || abs(grid[nowx][nowy]-grid[nex][ney])>lim)return 0;
    visited[nex][ney]=true;
    return 1+expand(nex,ney,nex+1,ney,lim)+expand(nex,ney,nex-1,ney,lim)+expand(nex,ney,nex,ney+1,lim)+expand(nex,ney,nex,ney-1,lim);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("tractor.in","r",stdin);
    freopen("tractor.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
        }
    }
    int l=0,r=1e9;
    while(l<r){
        int mid=(l+r)>>1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=false;
            }
        }
        bool xd=false;
        for(int i=0;i<n && !xd;i++){
            for(int j=0;j<n && !xd;j++){
                if(visited[i][j])continue;
                if(expand(i,j,i,j,mid)>=(n*n-1)/2+1)xd=true;
            }
        }
        if(xd)r=mid;
        else l=mid+1;
    }
    cout << l;
}