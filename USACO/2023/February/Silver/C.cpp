#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
using namespace std;
int n,m,a,b,c,d,last[200000],tiempo[200000],over[200000];
vector<pair<int,pair<int,int>>> graph[200000];
// va de x hora a ariport y a las z
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b >> c >> d;
        graph[--a].push_back({b,{--c,d}});
    }
    for(int i=0;i<n;i++){
        cin >> over[i];
        tiempo[i]=1e9+7;
        sort(REV(graph[i]));
    }
    tiempo[0]=0;
    priority_queue<pair<int,int>> dij;
    // tiempo, nodo
    dij.push({0,0});
    while(!dij.empty()){
        int top=dij.top().second;
        dij.pop();
        while(last[top]<graph[top].size() && graph[top][last[top]].first>=tiempo[top]+over[top]){
            if(tiempo[graph[top][last[top]].second.first]>graph[top][last[top]].second.second){
                tiempo[graph[top][last[top]].second.first]=graph[top][last[top]].second.second;
                dij.push({-graph[top][last[top]].second.second,graph[top][last[top]].second.first});
            }
            last[top]++;
        }
    }
    for(int i=0;i<n;i++)cout << ((tiempo[i]==1e9+7)?-1:tiempo[i]) << '\n';
}