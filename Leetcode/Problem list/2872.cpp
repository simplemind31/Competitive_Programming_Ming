#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mod,res;
    vector<vector<int>> arbol;
    vector<int> valores;
    void dfs(int now,int ante){
        for(auto u:arbol[now]){
            if(u==ante)continue;
            if(dfs(u,now),valores[u]==0)res++;
            valores[now]=(valores[now]+valores[u])%mod;
        }
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k){
        arbol.resize(n);
        valores.resize(n);
        mod=k;
        for(int i=res=0;i<n;i++)valores[i]=values[i]%k;
        for(auto par:edges){
            arbol[par[0]].push_back(par[1]);
            arbol[par[1]].push_back(par[0]);
        }
        dfs(0,-1);
        return res+1;
    }
};