#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a,b,c,pad[100000];
vector<pair<int,int>> graph[100000];
long double l,r=1e18;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b >> c;
        graph[--a].push_back({--b,c});
    }
    while(abs(r-l)>=1e-9){
        long double mid=(l+r)/2;
        //solo puede usar de mid para abajo
        vector<long double> dist(n,1e18);
        dist[0]=0;
        for(int i=0;i<n;i++){
            for(auto u:graph[i]){
                dist[u.first]=min(dist[u.first],dist[i]+u.second-mid);
            }
        }
        if(dist[n-1]<=0)r=mid;
        else l=mid;
    }
    vector<long double> dist(n,1e18);
    dist[0]=0;
    for(int i=0;i<n;i++){
        for(auto u:graph[i]){
            if(dist[i]+u.second-l<dist[u.first]){
                dist[u.first]=dist[i]+u.second-l;
                pad[u.first]=i;
            }
        }
    }
    vector<int> res;
    int now=n-1;
    res.push_back(now);
    while(now!=0)res.push_back(now=pad[now]);
    reverse(res.begin(),res.end());
    cout << res.size()-1 << '\n';
    for(auto u:res)cout << u+1 << ' ';
}