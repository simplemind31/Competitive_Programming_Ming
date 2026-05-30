#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n[2],m[2],a,b,q;
vector<vector<int>> graph[2];
vector<vector<int>> solve[2];
vector<bool> visited[2],posi[2];
void dfs(int node,int uni){
    if(visited[uni][node])return;
    visited[uni][node]=true;
    if(node==n[uni]-1){
        solve[uni][node].push_back(0);
        return;
    }
    for(auto u:graph[uni][node]){
        dfs(u,uni);
        int i=0,j=0;
        vector<int> nue;
        while(i<solve[uni][node].size() && j<solve[uni][u].size()){
            if(solve[uni][node][i]<solve[uni][u][j]+1)nue.push_back(solve[uni][node][i++]);
            else if(solve[uni][node][i]>solve[uni][u][j]+1){
                nue.push_back(solve[uni][u][j++]+1);
            }
            else{
                nue.push_back(solve[uni][u][i++]);
                j++;
            }
        }
        while(i<solve[uni][node].size())nue.push_back(solve[uni][node][i++]);
        while(j<solve[uni][u].size())nue.push_back(solve[uni][u][j++]+1);
        solve[uni][node]=nue;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<2;i++){
        cin >> n[i];
        graph[i].resize(n[i]);
        solve[i].resize(n[i]);
        visited[i].resize(n[i]);
        posi[i].resize(n[i]);
    }
    for(int i=0;i<2;i++)cin >> m[i];
    for(int i=0;i<2;i++){
        while(m[i]--){
            cin >> a >> b;
            graph[i][--a].push_back(--b);
            graph[i][b].push_back(a);
        }
        dfs(0,i);
        for(auto u:solve[i][0]){
            posi[i][u]=true;
            cout << u << ' ';
        }
        cout << endl;
    }
    cin >> q;
    while(q--){
        cin >> a;
        bool xd=false;
        for(int i=0;i<=min(a,n[0]-1) && xd;i++){
            if(posi[0][i] && posi[0][a-i]){
                xd=true;
            }
        }
        if(xd)cout << "Yes\n";
        else cout << "No\n";
    }
}