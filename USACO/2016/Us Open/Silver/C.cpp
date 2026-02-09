#include <bits/stdc++.h>
using namespace std;
bitset<3000> res,visited;
int n,m,dsu[3000],x,y,con,orden[3000],tam[3000];
vector<int> graph[3000];
int find(int a){return (a==dsu[a])?a:dsu[a]=find(dsu[a]);}
bool unite(int a,int b){
    if((a=find(a))==(b=find(b)))return false;
    if(tam[a]>tam[b])swap(a,b);
    tam[dsu[a]=b]+=tam[a];
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("closing.in","r",stdin);
    freopen("closing.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++)tam[dsu[i]=i]=1;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        graph[--x].push_back(--y);
        graph[y].push_back(x);
    }
    for(int i=0;i<n;i++)cin >> orden[i];
    reverse(orden,orden+n);
    for(int i=0;i<n;i++){
        visited[--orden[i]]=true;
        for(auto u:graph[orden[i]])if(visited[u])if(unite(u,orden[i]))con++;
        res[i]=con==i;
    }
    for(int i=n-1;i>=0;i--)cout << (res[i]?"YES\n":"NO\n");
}