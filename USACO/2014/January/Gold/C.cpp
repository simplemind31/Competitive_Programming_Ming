#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,t,a;
vector<bool> start;
ll res;
struct DSU{
    vector<int> tam,pad,important;
    int find(int x){return x==pad[x]?x:pad[x]=find(pad[x]);}
    bool unite(int x,int y){
        if((x=find(x))==(y=find(y)))return false;
        if(important[x]<important[y])swap(x,y);
        important[x]+=important[y];
        tam[pad[y]=x]+=tam[y];
        return true;
    }
    DSU(int x){
        tam.resize(x);
        pad.resize(x);
        important.resize(x);
        for(int i=0;i<x;i++){
            tam[pad[i]=i]=1;
            important[i]=start[i];
        }
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("skilevel.in","r",stdin);
    freopen("skilevel.out","w",stdout);
    cin >> n >> m >> t;
    int mat[n][m];
    start.resize(n*m);
    vector<pair<int,pair<int,int>>> dif;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cin >> mat[i][j];
        for(int j=1;j<m;j++)dif.push_back({abs(mat[i][j]-mat[i][j-1]),{i*m+j,i*m+j-1}});
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            dif.push_back({abs(mat[i][j]-mat[i-1][j]),{i*m+j,(i-1)*m+j}});
        }
    }
    sort(ALL(dif));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a;
            start[i*m+j]=a;
        }
    }
    DSU clav(n*m);
    for(auto u:dif){
        clav.unite(u.second.first,u.second.second);
        int head=clav.find(u.second.first);
        if(clav.tam[head]>=t){
            //if(clav.important[head].size())cout << clav.important[head][0] << ' ' << u.first << '\n';
            res+=1ll*clav.important[head]*u.first;
            clav.important[head]=0;
        }
    }
    cout << res;
}