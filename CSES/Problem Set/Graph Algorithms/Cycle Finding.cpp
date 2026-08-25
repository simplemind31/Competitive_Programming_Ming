#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,head;
vector<int> res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector<ll> distance(n+1,1e18);
    vector<int> pad(n+1);
    for(int i=1;i<=n;i++)pad[i]=i;
    vector<pair<pair<int,int>,ll>> edges(m);
    for(int i=0;i<m;i++)cin >> edges[i].first.first >> edges[i].first.second >> edges[i].second;
    distance[1]=0;
    for(int i=1;i<n;i++){
        for(auto u:edges){
            distance[u.first.second]=min(distance[u.first.second],distance[u.first.first]+u.second);
            pad[u.first.second]=u.first.first;
        }
    }
    for(int i=1;i<2*n;i++){
        for(auto u:edges){
            if(distance[u.first.first]+u.second<distance[u.first.second]){
                distance[u.first.second]=distance[u.first.first]+u.second;
                head=u.first.second;
                pad[u.first.second]=u.first.first;
            }
        }
    }
    if(!head){
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    vector<bool> visited(n+1);
    res.push_back(head);
    visited[head]=1;
    while(!visited[head=pad[head]]){
        visited[head]=true;
        res.push_back(head);
    }
    res.push_back(head);
    reverse(res.begin(),res.end());
    cout << res[0] << ' ';
    for(int i=1;i<res.size();i++){
        cout << res[i] << ' ';
        if(res[i]==res[0])break;
    }
}