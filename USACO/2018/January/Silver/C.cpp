#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,dsu[100000],tam[100000];
// de mayor a menor, dsu;
int find(int a){return (a==dsu[a])?a:dsu[a]=find(dsu[a]);}
bool unite(int a,int b){
    if((a=find(a))==(b=find(b)))return false;
    if(tam[b]>tam[a])swap(a,b);
    tam[dsu[b]=a]+=tam[b];
}
int main(){
    freopen("mootube.in","r",stdin);
    freopen("mootube.out","w",stdout);
    cin >> n >> q;
    for(int i=0;i<n;i++)tam[dsu[i]=i]=1;
    pair<int,pair<int,int>> edges[n-1];
    for(int i=0;i<n-1;i++){
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    }
    sort(edges,edges+n);
    reverse(edges,edges+n);
    pair<pair<int,int>,int> querys[q];
    int res[q];
    memset(res,0,sizeof(res));
    for(int i=0;i<q;i++){
        cin >> querys[i].first.first >> querys[i].first.second >> querys[i].second;
    }
    sort(querys,querys+q);
    for(int i=0;i<q;i++){
        / 
    }
}