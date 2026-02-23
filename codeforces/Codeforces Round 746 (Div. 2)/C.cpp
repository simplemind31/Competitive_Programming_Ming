#include <bits/stdc++.h>
using namespace std;
int t,n,a,b,tar,k;
vector<vector<int>> graph;
vector<int> val;
int dfs(int node,int ante){
    int can=0;
    for(auto u:graph[node]){
        if(u==ante)continue;
        int temp=dfs(u,node);
        can+=temp;
        val[node]^=val[u];
    }
    if(val[node]==tar){
        can++;
        val[node]=0;
    }
    return can;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        graph.clear();
        val.clear();
        cin >> n >> k;
        tar=0;
        graph.resize(n);
        val.resize(n);
        for(int i=0;i<n;i++){
            cin >> val[i];
            tar^=val[i];
        }
        for(int i=1;i<n;i++){
            cin >> a >> b;
            graph[--a].push_back(--b);
            graph[b].push_back(a);
        }
        if(tar==0){
            cout << "YES\n";
            continue;
        }
        if(k==2){
            cout << "NO\n";
            continue;
        }
        cout << ((dfs(0,-1)>=3 && val[0]==0)?"YES\n":"NO\n");
    }
}