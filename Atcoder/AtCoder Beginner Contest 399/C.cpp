#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend();
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
bool visited[200000];
int n,a,m,b;
vector<int> graph[200000];
void dfs(int node){
    visited[node]=true;
    for(auto u:graph[node])if(!visited[u])dfs(u);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    b=0;
    for(int i=0;i<n;i++){
        b+=!visited[i];
        if(!visited[i])dfs(i);
    }
    // hay b comp, cada comp hay x-1 edges, entonces debe haber n-b
    cout << m-(n-b);
}