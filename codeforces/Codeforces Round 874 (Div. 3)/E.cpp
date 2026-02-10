#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bitset<200000> visited;
int t,n,a,con,res;
pair<int,int> nums[200000];
vector<vector<int>> graph;
bool dfs(int node){
    bool xd=(nums[node].second==-1);
    visited[node]=true;
    for(auto u:graph[node]){
        if(visited[u])continue;
        xd|=dfs(u);
    }
    return xd;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        graph.clear();
        graph.resize(n);
        res=con=0;
        for(int i=0;i<n;i++){
            visited[i]=0;
            nums[i]={-1,-1};
        }
        for(int i=0;i<n;i++){
            cin >> a;
            a--;
            if(nums[i].first==-1 || nums[i].first==a)nums[i].first=a;
            else nums[i].second=a;
            if(nums[a].first==-1 || nums[a].first==i)nums[a].first=i;
            else nums[a].second=i;
        }
        for(int i=0;i<n;i++){
            graph[i].push_back(nums[i].first);
            if(nums[i].second!=-1)graph[i].push_back(nums[i].second);
        }
        for(int i=0;i<n;i++){
            if(visited[i])continue;
            con++;
            res+=dfs(i);
        }
        if(res==0)cout << con << ' ' << con << '\n';
        else cout << con-res+1 << ' ' << con << '\n';
    }
}