#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,clocks[2500],a,b,res,temp[2500],can0;
vector<int> graph[2500];
void dfs(int node,int ante){
    //visitar cada hijo
    for(auto u:graph[node]){
        if(u==ante)continue;
        if(temp[u]==0)can0--;
        temp[u]=(temp[u]+1)%12;
        if(temp[u]==0)can0++;
        dfs(u,node);
    }
    // volver al padre y que complete
    if(ante!=-1){
        if(temp[ante]==0)can0--;
        temp[ante]=(temp[ante]+(12-temp[node]))%12;
        if(temp[ante]==0)can0++;
        if(temp[node]==0)can0--;
        temp[node]=0;
        if(temp[node]==0)can0++;
        if(can0==n)return;
        if(temp[ante]==0)can0--;
        temp[ante]=(temp[ante]+1)%12;
        if(temp[ante]==0)can0++;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("clocktree.in","r",stdin);
    freopen("clocktree.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++)cin >> clocks[i];
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        for(int j=can0=0;j<n;j++)can0+=((temp[j]=((clocks[j])%12))==0);
        dfs(i,-1);
        if(can0==n)res++;   
    }
    cout << res;
}