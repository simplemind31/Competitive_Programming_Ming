#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
struct dsu{
    int compo,maxi=1;
    vector<int> pad,tam;
    int find(int a){return (a==pad[a])?a:pad[a]=find(pad[a]);}
    bool unite(int a,int b){
        if((a=find(a))==(b=find(b)))return false;
        compo--;
        if(tam[a]<tam[b])swap(a,b);
        maxi=max(tam[pad[b]=a]+=tam[b],maxi);
        return true;
    }
    dsu(int x){
        compo=x;
        tam.resize(x);
        pad.resize(x);
        for(int i=0;i<x;i++)tam[pad[i]=i]=1;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    dsu clav(n);
    while(m--){
        cin >> a >> b;
        clav.unite(--a,--b);
    }
    cout << "Existen " << clav.compo << " posibles tipos\nEl tipo con mas Pokemon tiene " << clav.maxi;
}