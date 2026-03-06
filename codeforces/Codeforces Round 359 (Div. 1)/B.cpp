#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
const int MAXN=300000;
int n,q,a,hij[MAXN][20],tam[MAXN];
vector<int> graph[MAXN];
void dfs(int node,int ante){
    tam[node]=1;
    hij[node][0]=node;
    int maxi=0;
    for(auto u:graph[node]){
        if(u==ante)continue;
        dfs(u,node);
        tam[node]+=tam[u];
        if(tam[u]>maxi){
            maxi=tam[u];
            hij[node][0]=u;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for(int i=1;i<n;i++){
        cin >> a;
        graph[--a].push_back(i);
        graph[i].push_back(a);
    }
    dfs(0,-1);
    for(int i=1;i<20;i++){
        for(int j=0;j<n;j++){
            hij[j][i]=hij[hij[j][i-1]][i-1];
        }
    }
    //for(int i=0;i<n;i++)cout << hij[i][0] << ' ';
    //cout << '\n';
    while(q--){
        cin >> a;
        a--;
        int tot=tam[a];
        //cout << tot << ' ';
        for(int i=19;i>=0;i--){
            if(tot-tam[hij[a][i]]<=tot/2)a=hij[a][i];
        }
        cout << a+1 << '\n';
    }
}