#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int t=1,n,a,b;
vector<vi> graph;
vector<vector<bool>> posi;
void solve(int now,int ante){
    if(graph[now][0]==ante && graph[now].size()==1){
        // leaf
        posi[now]={0,1,0};
        return;
    }
    vector<bool> temp[2];
    temp[0]=temp[1]={false,false,false};
    temp[0][0]=true;
    bool xd=false;
    for(auto u:graph[now]){
        if(u==ante)continue;
        solve(u,now);
        xd=!xd;
        for(int i=0;i<3;i++)temp[xd][i]=false;
        if((temp[!xd][0]&&posi[u][1])||(temp[!xd][1]&&posi[u][0])||(temp[!xd][2]&&posi[u][2]))temp[xd][1]=true;
        if((temp[!xd][0]&&posi[u][0])||(temp[!xd][1]&&posi[u][2])||(temp[!xd][2]&&posi[u][1]))temp[xd][0]=true;
        if((temp[!xd][0]&&posi[u][2])||(temp[!xd][2]&&posi[u][0])||(temp[!xd][1]&&posi[u][1]))temp[xd][2]=true;
    }
    posi[now][0]=temp[xd][0];
    posi[now][1]=true;
    posi[now][2]=temp[xd][2];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        graph.clear();
        graph.resize(n);
        posi.assign(n,{false,false,false});
        for(int i=1;i<n;i++){
            cin >> a >> b;
            graph[--a].push_back(--b);
            graph[b].push_back(a);
        }
        solve(0,-1);
        if(posi[0][0])cout << "YES\n";
        else cout << "NO\n";
    }
}