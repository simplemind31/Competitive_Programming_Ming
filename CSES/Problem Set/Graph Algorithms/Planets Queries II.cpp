#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bitset<200001> pertenece,visited;
int n,q,ne[200001][20],a,b,head[200001],dist[200001];
void findciclo(int x){
    if(head[x])return;
    if(visited[x]){
        head[x]=x;
        dist[x]=0;
        return;
    }
    visited[x]=true;
    findciclo(ne[x][0]);
    head[x]=head[ne[x][0]];
    dist[x]=dist[ne[x][0]]+1;
    return;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++)cin >> ne[i][0];
    for(int j=1;j<20;j++)for(int i=1;i<=n;i++)ne[i][j]=ne[ne[i][j-1]][j-1];
    for(int i=1;i<=n;i++)if(!head[i])findciclo(i);
    // cada nodo siempre llegará a un ciclo
    for(int i=1;i<=n;i++){
        if(head[i]!=i)continue;
        pertenece[i]=true;
        int now=ne[i][0];
        while(now!=i){
            pertenece[now]=1;
            now=ne[now][0];
        }
    }
    while(q--){
        cin >> a >> b;
        int oa=a;
        if(head[a]!=head[b] || (!pertenece[b] && dist[a]-dist[b]<0)){
            cout << "-1\n";
            continue;
        }
        // dos posibilidades, b esta en camino de a a head
        // o b esta despues
        int need1=dist[a]-dist[b];
        int need2=dist[a]+dist[ne[head[a]][0]]+1-dist[b];
        if(need1>=0)for(int j=19;j>=0;j--)if(need1&(1<<j))a=ne[a][j];
        if(a==b){
            cout << need1 << '\n';
            continue;
        }
        a=oa;
        if(need2>=0)for(int j=19;j>=0;j--)if(need2&(1<<j))a=ne[a][j];
        if(a==b)cout << need2 << '\n';
        else cout << "-1\n";
    }
}