#include <bits/stdc++.h>
using namespace std;
int x,n,con;
vector<int> dsu,tam;
int find(int a){return (a==dsu[a])?a:dsu[a]=find(dsu[a]);}
bool unite(int a,int b){
    if((a=find(a))==(b=find(b)))return false;
    if(tam[b]>tam[a])swap(a,b);
    tam[a]+=tam[b];
    dsu[b]=a;
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    dsu.resize(n);
    tam=dsu;
    for(int i=0;i<n;i++)tam[dsu[i]=i]=1;
    for(int i=0;i<n;i++){
        cin >> x;
        if(unite(--x,i))con++;
    }
    cout << n-con;
}