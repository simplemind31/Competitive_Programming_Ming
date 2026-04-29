#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,t,m,a,d,k;
struct DSU{
    int compo;
    vector<int> pad,tam;
    int find(int x){return x==pad[x]?x:pad[x]=find(pad[x]);}
    bool unite(int a,int b){
        if((a=find(a))==(b=find(b)))return false;
        if(tam[a]<tam[b])swap(a,b);
        tam[pad[b]=a]+=tam[b];
        compo--;
        return true;
    }
    DSU(int x){
        compo=x;
        pad.resize(x);
        tam.resize(x);
        for(int i=0;i<x;i++)tam[pad[i]=i]=1;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<pair<int,int>> mod[11][10];
        while(m--){
            cin >> a >> d >> k;
            mod[d][(a-1)%d].push_back({a-1,a-1+d*k});
        }
        DSU clav(n);
        for(int i=1;i<=10;i++){
            for(int j=0;j<10;j++){
                if(mod[i][j].empty())continue;
                sort(ALL(mod[i][j]));
                // si se intersectan se reducen
                vector<pair<int,int>> nue;
                nue.push_back(mod[i][j][0]);
                for(int k=1;k<mod[i][j].size();k++){
                    if(mod[i][j][k].first<=nue.back().second)nue.back().second=max(mod[i][j][k].second,nue.back().second);
                    else nue.push_back(mod[i][j][k]);
                }
                // unir
                for(auto u:nue){
                    while(u.first<u.second){
                        clav.unite(u.first,u.second);
                        u.first+=i;
                    }
                }
            }
        }
        cout << clav.compo << '\n';
    }
}