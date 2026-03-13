#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200000;
int n,k,a,b,val[MAXN],sig1[MAXN],pad[MAXN],maximos[MAXN],maxiraiz[MAXN][2],maxihiji[MAXN][2];
ll solve2[MAXN],raiz[MAXN];
vector<int> graph[MAXN];
ll dfs1(int node,int ante){
    ll maxi=0;
    for(auto u:graph[node]){
        if(u==ante)continue;
        pad[u]=node;
        ll temp=dfs1(u,node);
        if(temp>maxi){
            maxi=temp;
            sig1[node]=u;
        }
    }
    if(maxi==0)sig1[node]=node;
    return val[node]+maxi;
}

int condis=0;
ll suma3;
vector<int> res3;
void dfs3(int node,int ante){
    bool xd=false;
    if(condis==3){
        res3.push_back(node);
        suma3+=val[node];
        condis=0;
        xd=true;
    }
    for(auto u:graph[node]){
        if(u==ante)continue;
        condis++;
        dfs3(u,node);
    }
    if(!xd){
        condis=0;
        suma3+=val[node];
        res3.push_back(node);
    }
    condis++;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    for(int i=0;i<n;i++)cin >> val[i];
    if(k==1){
        cout << dfs1(0,-1) << '\n';
        vector<int> res;
        int now=0;
        while(now!=sig1[now]){
            res.push_back(now);
            now=sig1[now];
        }
        res.push_back(now);
        cout << res.size() << '\n';
        for(auto u:res)cout << u+1 << ' ';
        return 0;
    }else if(k==2){
        /*
        dp1[i]
        */
        return 0;
    }else{
        condis=3;
        dfs3(0,-1);
        cout << suma3 << '\n';
        cout << res3.size() << '\n';
        for(auto u:res3)cout << u+1 << ' ';
        return 0;
    }
}