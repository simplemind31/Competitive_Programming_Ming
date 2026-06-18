#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct dsu{
    vector<int> pad,tam;
    int find(int x){return x==pad[x]?x:pad[x]=find(pad[x]);}
    bool unite(int x,int y){
        if((x=find(x))==(y=find(y)))return false;
        if(tam[x]<tam[y])swap(x,y);
        tam[pad[y]=x]+=tam[y];
        return true;
    }
    dsu(int x){
        pad.resize(x);
        tam.resize(x);
        for(int i=0;i<x;i++)tam[pad[i]=i]=1;
    }
};
int n;
ll res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("superbull.in","r",stdin);
    freopen("superbull.out","w",stdout);
    cin >> n;
    dsu clav(n);
    int nums[n];
    vector<pair<int,pair<int,int>>> ed;
    for(int i=0;i<n;i++){
        cin >> nums[i];
        for(int j=0;j<i;j++){
            ed.push_back({nums[i]^nums[j],{i,j}});
        }
    }
    sort(ed.rbegin(),ed.rend());
    for(auto u:ed){
        if(clav.unite(u.second.first,u.second.second))res+=u.first;
    }
    cout << res;
}