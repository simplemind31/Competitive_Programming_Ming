#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> posi;
    vector<vector<int>> graph;
    void expand(int node){
        for(auto u:graph[node]){
            if(posi[u]!=posi[node]){
                posi[u]=posi[node];
                expand(u);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations){
        graph.clear();
        posi.clear();
        posi.resize(n);
        graph.resize(n);
        for(auto u:invocations)graph[u[0]].push_back(u[1]);
        posi[k]=1;
        expand(k);
        vector<int> res;
        for(int i=0;i<n;i++)if(!posi[i])for(auto u:graph[i])if(posi[u]){
            for(int i=0;i<n;i++)res.push_back(i);
            return res;
        }
        for(int i=0;i<n;i++)if(!posi[i])res.push_back(i);
        return res;
    }
};