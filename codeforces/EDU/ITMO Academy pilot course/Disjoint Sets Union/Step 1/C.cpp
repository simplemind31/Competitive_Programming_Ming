#include <bits/stdc++.h>
using namespace std;
int n,q,a,b;
string st;
vector<int> dsu,tam,res;
int find(int a){
    if(a==dsu[a])return a;
    if(dsu[a]!=dsu[dsu[a]]){
        find(dsu[a]);
        res[a]+=res[dsu[a]];
    }
    return dsu[a]=dsu[dsu[a]];
}
bool unite(int a,int b){
    if((a=find(a))==(b=find(b)))return false;
    if(tam[a]<tam[b])swap(a,b);
    tam[dsu[b]=a]+=tam[b];
    res[b]-=res[a];
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    dsu.resize(n);
    tam.resize(n);
    res.resize(n);
    for(int i=0;i<n;i++)tam[dsu[i]=i]=1;
    while(q--){
        cin >> st;
        if(st=="add"){
            cin >> a >> b;
            res[find(--a)]+=b;
        }else if(st=="join"){
            cin >> a >> b;
            unite(--a,--b);
        }else{
            cin >> a;
            find(--a);
            if(a==dsu[a])cout << res[a] << '\n';
            else cout << res[a]+res[dsu[a]] << '\n';
        }
    }
}