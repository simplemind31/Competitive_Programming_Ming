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
    return true;
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
    sort(edges,edges+n-1);
    reverse(edges,edges+n-1);
    pair<pair<int,int>,int> querys[q];
    int res[q];
    memset(res,0,sizeof(res));
    for(int i=0;i<q;i++){
        cin >> querys[i].first.first >> querys[i].first.second;
        querys[i].second=i;
    }
    sort(querys,querys+q);
    reverse(querys,querys+q);
    int j=0;
    for(int i=0;i<q;i++){
        while(j<n-1 && edges[j].first>=querys[i].first.first){
            unite(edges[j].second.first-1,edges[j].second.second-1);
            j++;
        }
        res[querys[i].second]=tam[find(querys[i].first.second-1)];
    }
    for(int i=0;i<q;i++){
        cout << res[i]-1 << '\n';
    }
}