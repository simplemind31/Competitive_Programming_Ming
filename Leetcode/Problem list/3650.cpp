#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<pair<int,int>>> graph;
    int minCost(int n, vector<vector<int>>& edges){
        graph.clear();
        graph.resize(n);
        for(auto u:edges){
            graph[u[0]].push_back({u[1],u[2]});
            graph[u[1]].push_back({u[0],2*u[2]});
        }
        vector<int> dist(n,2e9);
        vector<bool> visited(n);
        dist[0]=0;
        priority_queue<pair<int,int>> dij;
        dij.push({0,0});
        while(!dij.empty()){
            int top=dij.top().second;
            dij.pop();
            if(visited[top])continue;
            visited[top]=true;
            for(auto u:graph[top]){
                if(dist[u.first]>dist[top]+u.second){
                    dist[u.first]=dist[top]+u.second;
                    dij.push({-dist[u.first],u.first});
                }
            }
        }
        return (dist[n-1]==2e9)?-1:dist[n-1];
    }
};