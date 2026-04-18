#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,k,a,ord[5000];
ll mini=1e18,now;
bitset<5000> usado;
vector<int> posihijo[5000];
vector<vector<int>> graph;
int dfs(int node){
    int tam=1;
    for(auto u:graph[node]){
        tam+=dfs(u);
    }
    now+=tam;
    return tam;
}
bool cmp(int a,int b){
    return posihijo[a].size()>posihijo[b].size();
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
    cin >> n;
    for(int i=0;i<n;i++){
        ord[i]=i;
        cin >> k;
        while(k--){
            cin >> a;
            posihijo[--a].push_back(i);
        }
    }
    //reverse(ord,ord+n);
    //shuffle(ord,ord+n,(rng));
    //for(int i=0;i<n;i++)cout << ord[i] << ' ';
    sort(ord,ord+n,cmp);
    for(int i=0;i<n && (double)clock()/CLOCKS_PER_SEC<=1.6;i++){
        graph.clear();
        graph.resize(n);
        usado=0;
        queue<int> bfs;
        usado[ord[i]]=true;
        bfs.push(ord[i]);
        int con=1;
        while(!bfs.empty()){
            int top=bfs.front();
            bfs.pop();
            for(auto u:posihijo[top]){
                if(usado[u])continue;
                usado[u]=true;
                con++;
                graph[top].push_back(u);
                bfs.push(u);
            }
        }
        if(con!=n)continue;
        now=0;
        dfs(ord[i]);
        mini=min(mini,now);
    }
    cout << mini;
}