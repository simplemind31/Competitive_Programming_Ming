#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector<int> graph[n],deg(n);
    while(m--){
        cin >> a >> b;
        graph[--b].push_back(--a);
        deg[a]++;
    }
    priority_queue<int> posible;
    for(int i=0;i<n;i++)if(!deg[i])posible.push(i);
    vector<int> res;
    while(!posible.empty()){
        int top=posible.top();
        posible.pop();
        res.push_back(top);
        for(auto u:graph[top]){
            if(--deg[u]==0)posible.push(u);
        }
    }
    reverse(res.begin(),res.end());
    vector<int> pos(n);
    for(int i=0;i<n;i++)cout << res[i]+1 << ' ';
}