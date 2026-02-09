#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,a,b,alt[200000],pad[200000][20],k;
vector<int> graph[200000];
void dfs(int node,int ante){
    for(auto u:graph[node]){
        if(u==ante)continue;
        pad[u][0]=node;
        alt[u]=alt[node]+1;
        dfs(u,node);
    }
}
bool cmp(int x,int y){return alt[x]<alt[y];}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,-1);
    for(int i=1;i<20;i++)for(int j=0;j<n;j++)pad[j][i]=pad[pad[j][i-1]][i-1];
    while(q--){
        cin >> k;
        int nums[k];
        for(int i=0;i<k;i++){
            cin >> nums[i];
            nums[i]=pad[--nums[i]][0];
        }
        sort(nums,nums+k,cmp);
        // existe un camino que contenga a todos nums[i]?;
        int now=nums[k-1];
        bool xd=true;
        for(int i=k-2;i>=0 && xd;i--){
            //igualar altura de now con nums[i];
            for(int j=19;j>=0;j--)if(alt[pad[now][j]]>=alt[nums[i]])now=pad[now][j];
            if(now!=nums[i])xd=false;
        }
        if(xd)cout << "YES\n";
        else cout << "NO\n";
    }
}