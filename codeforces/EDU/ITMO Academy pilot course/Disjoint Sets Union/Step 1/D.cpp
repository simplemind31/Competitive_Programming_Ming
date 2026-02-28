#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,k;
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
    cin >> n >> m >> k;
    dsu.resize(n);
    tam.resize(n);
    pair<string,pair<int,int>> op[k];
    for(int i=0;i<n;i++)tam[dsu[i]=i]=1;
    while(m--)cin >> a >> b;
    for(int i=k-1;i>=0;i--)cin >> op[i].first >> op[i].second.first >> op[i].second.second;
    vector<bool> res;
    for(int i=0;i<k;i++){
        if(op[i].first=="ask")res.push_back(find(op[i].second.first-1)==find(op[i].second.second-1));
        else unite(op[i].second.first-1,op[i].second.second-1);
    }
    reverse(res.begin(),res.end());
    for(auto u:res)cout << (u?"YES":"NO") << '\n';
}