#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
string st;
vector<int> dsu,tam;
int find(int a){return (a==dsu[a])?a:dsu[a]=find(dsu[a]);}
bool unite(int a,int b){
    if((a=find(a))==(b=find(b)))return false;
    if(tam[a]<tam[b])swap(a,b);
    tam[dsu[b]=a]+=tam[b];
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    dsu.resize(n);
    tam.resize(n);
    for(int i=0;i<n;i++)tam[dsu[i]=i]=1;
    while(m--){
        cin >> st >> a >> b;
        if(st=="union")unite(--a,--b);
        else cout << ((find(--a)==find(--b))?"YES":"NO") << '\n';
    }
}