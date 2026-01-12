#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef vector<int> vi;
int t,n,a,b,res;
vector<vi> graph;
int solve(int now,int ante){
    vector<int> posi;
    for(auto u:graph[now])if(u!=ante)posi.push_back(solve(u,now));
    if(posi.empty())return 0;
    res=max(res,posi[0]+1);
    if(posi.size()==1)return max(posi[0],1);
    sort(REV(posi));
    res=max(res,(int)max({posi.size(),posi[0]+posi.size()-1,posi[0]+posi[1]+posi.size()-2})+(now!=0));
    return max(posi[0]+posi.size()-1,posi.size());
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        graph.assign(n,{});
        for(int i=res=1;i<n;i++){
            cin >> a >> b;
            graph[--a].push_back(--b);
            graph[b].push_back(a);
        }
        solve(0,-1);
        cout << res << '\n';
    }
}