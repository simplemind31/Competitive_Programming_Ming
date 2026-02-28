#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
string st;
vector<int> dsu,tam,mini,maxi;
int find(int a){return (a==dsu[a])?a:dsu[a]=find(dsu[a]);}
bool unite(int a,int b){
    if((a=find(a))==(b=find(b)))return false;
    if(tam[a]<tam[b])swap(a,b);
    tam[dsu[b]=a]+=tam[b];
    mini[a]=min(mini[a],mini[b]);
    maxi[a]=max(maxi[a],maxi[b]);
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    dsu.resize(n);
    tam.resize(n);
    mini.resize(n);
    maxi.resize(n);
    for(int i=0;i<n;i++)tam[mini[i]=maxi[i]=dsu[i]=i]=1;
    while(m--){
        cin >> st;
        if(st=="union"){
            cin >> a >> b;
            unite(--a,--b);
        }else{
            cin >> a;
            int head=find(--a);
            cout << mini[head]+1 << ' ' << maxi[head]+1 << ' ' << tam[head] << '\n';
        }
    }
}