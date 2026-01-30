#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,d,a,b,c,l,r=(1e9)+1,pad[100000];
vector<pair<int,int>> graph[100000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> d;
    while(m--){
        cin >> a >> b >> c;
        graph[--a].push_back({--b,c});
    }
    while(l<r){
        int mid=(l+r)>>1;
        //solo puede usar de mid para abajo
        vector<int> dist(n,1e9);
        queue<int> bfs;
        bfs.push(0);
        dist[0]=0;
        while(!bfs.empty()){
            int top=bfs.front();
            bfs.pop();
            for(auto u:graph[top]){
                if(!(dist[u.first]==1e9 && u.second<=mid))continue;
                dist[u.first]=dist[top]+1;
                bfs.push(u.first);
            }
        }
        if(dist[n-1]<=d)r=mid;
        else l=mid+1;
    }
    if(l==1000000001){
        cout << -1;
        return 0;
    }
    vector<int> dist(n,1e9);
    queue<int> bfs;
    bfs.push(0);
    dist[0]=0;
    while(!bfs.empty()){
        int top=bfs.front();
        bfs.pop();
        for(auto u:graph[top]){
            if(!(dist[u.first]==1e9 && u.second<=l))continue;
            dist[u.first]=dist[top]+1;
            bfs.push(u.first);
            pad[u.first]=top;
        }
    }
    vector<int> res;
    int now=n-1;
    res.push_back(n-1);
    while(now!=0)res.push_back(now=pad[now]);
    reverse(res.begin(),res.end());
    cout << res.size()-1 << '\n';
    for(auto u:res)cout << u+1 << ' ';
}