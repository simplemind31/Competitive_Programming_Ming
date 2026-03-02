#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,m,x,y,con;
vector<bool> visited;
vector<vector<int>> NOgraph;
vector<vector<pair<int,int>>> graph;
struct segment{
    int tam;
    vector<bool> st;
    queue<pair<int,int>> nums;
    segment(int x){
        tam=x;
        st.resize(4*tam+5);
    }
    void update(int node,int l,int r,int i,int j){
        if(st[node])return;
        if(r<i ||j<l)return;
        if(i<=l && r<=j){
            st[node]=true;
            nums.push({l,r});
            return;
        }
        int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
        update(hiji,l,mid,i,j);
        update(hijd,mid+1,r,i,j);
    }
    queue<pair<int,int>> u(int i,int j){
        while(!nums.empty())nums.pop();
        update(0,0,tam-1,i,j);
        return nums;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    NOgraph.resize(n);
    visited.resize(n);
    graph.resize(n);
    for(int i=0;i<n;i++){
        NOgraph[i].push_back(-1);
        NOgraph[i].push_back(n);
    }
    while(m--){
        cin >> x >> y;
        NOgraph[--x].push_back(--y);
        NOgraph[y].push_back(x);
    }
    for(int i=0;i<n;i++){
        sort(ALL(NOgraph[i]));
        for(int j=1;j<NOgraph[i].size();j++){
            if(NOgraph[i][j-1]+1<=NOgraph[i][j]-1)graph[i].push_back({NOgraph[i][j-1]+1,NOgraph[i][j]-1});
        }
    }
    segment clave(n);
    for(int i=0;i<n;i++){
        if(visited[i])continue;
        con++;
        queue<pair<int,int>> bfs;
        bfs.push({i,i});
        while(!bfs.empty()){
            pair<int,int> top=bfs.front();
            bfs.pop();
            for(int j=top.first;j<=top.second;j++){
                if(!visited[j]){
                    visited[j]=true;
                    for(int k=0;k<graph[j].size();k++){
                        queue<pair<int,int>> nue=clave.u(graph[j][k].first,graph[j][k].second);
                        while(!nue.empty()){
                            bfs.push(nue.front());
                            nue.pop();
                        }
                    }
                }
            }
        }
    }
    cout << con-1;
}