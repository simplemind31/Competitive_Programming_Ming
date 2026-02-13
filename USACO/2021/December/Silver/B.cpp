#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,n,m,a,b;
vector<vector<int>> graph;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        graph.clear();
        graph.resize(n);
        while(m--){
            cin >> a >> b;
            graph[--a].push_back(--b);
            graph[b].push_back(a);
        }
        vector<bool> visited(n);
        vector<int> pad(n),p1,pn,mini1(n,1e9),minin(n,1e9);
        queue<int> bfs;
        for(int i=0;i<n;i++){
            if(visited[i])continue;
            visited[i]=true;
            bfs.push(i);
            while(!bfs.empty()){
                int top=bfs.front();
                bfs.pop();
                pad[top]=i;
                for(auto u:graph[top]){
                    if(visited[u])continue;
                    visited[u]=true;
                    bfs.push(u);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(pad[i]==pad[0])p1.push_back(i);
            if(pad[i]==pad[n-1])pn.push_back(i);
        }
        
        for(int i=0;i<n;i++){
            //pad[0]->pad[i]->pad[n-1]
            int pos=lower_bound(ALL(p1),i)-p1.begin();
            if(pos==p1.size()){
                mini1[pad[i]]=min(mini1[pad[i]],i-p1[pos-1]);
            }else if(pos==0){
                mini1[pad[i]]=min(mini1[pad[i]],p1[pos]-i);
            }else{
                mini1[pad[i]]=min({mini1[pad[i]],i-p1[pos-1],p1[pos]-i});
            }

            pos=lower_bound(ALL(pn),i)-pn.begin();
            if(pos==pn.size()){
                minin[pad[i]]=min(minin[pad[i]],i-pn[pos-1]);
            }else if(pos==0){
                minin[pad[i]]=min(minin[pad[i]],pn[pos]-i);
            }else{
                minin[pad[i]]=min({minin[pad[i]],i-pn[pos-1],pn[pos]-i});
            }
        }
        ll res=1e18;
        for(int i=0;i<n;i++){
            res=min(res,1ll*mini1[i]*mini1[i]+1ll*minin[i]*minin[i]);
        }
        cout << res << '\n';
    }
}