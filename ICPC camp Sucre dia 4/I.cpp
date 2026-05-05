#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
using namespace std;
struct DSU{
    int compo;
    vector<int> pad,tam;
    int find(int x){return x==pad[x]?x:pad[x]=find(pad[x]);}
    bool unite(int x,int y){
        if((x=find(x))==(y=find(y)))return false;
        if(tam[x]<tam[y])swap(x,y);
        tam[pad[y]=x]+=tam[y];
        compo--;
        return true;
    }
    DSU(int x){
        compo=x;
        tam.resize(x);
        pad.resize(x);
        for(int i=0;i<x;i++)tam[pad[i]=i]=1;
    }
};
int n,m,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    DSU clav(n);
    while(m--){
        cin >> a >> b;
        clav.unite(--a,--b);
    }
    cout << clav.compo-1 << '\n';
    for(int i=0;i<n;i++){
        if(clav.unite(0,i))cout << 1 << ' ' << i+1 << '\n';
    }
}
