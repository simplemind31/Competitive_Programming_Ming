#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct DSU{
        vector<int> pad,tam;
        int find(int a){return a==pad[a]?a:pad[a]=find(pad[a]);}
        bool unite(int a,int b){
            if((a=find(a))==(b=find(b)))return false;
            if(tam[a]<tam[b])swap(a,b);
            tam[pad[b]=a]+=tam[b];
            return true;
        }
        DSU(int n){
            pad.resize(n);
            tam.resize(n);
            for(int i=0;i<n;i++)tam[pad[i]=i]=1;
        }
    };
    int maxStability(int n,vector<vector<int>>& edges,int k){
        DSU clave(n);
        int m=edges.size(),mini=1e9;
        for(int i=0;i<m;i++){
            if(edges[i][3]){
                if(!clave.unite(edges[i][0],edges[i][1]))return -1;
                mini=min(mini,edges[i][2]);
            }
            swap(edges[i][0],edges[i][2]);
        }
        sort(edges.rbegin(),edges.rend());
        vector<int> usado;
        for(int i=0;i<m;i++){
            if(edges[i][3])continue;
            if(clave.unite(edges[i][1],edges[i][2])){
                usado.push_back(edges[i][0]);
            }
        }
        if(clave.tam[clave.find(0)]!=n)return -1;
        reverse(usado.begin(),usado.end());
        n=usado.size();
        for(int i=0;i<min(n,k);i++){
            usado[i]*=2;
        }
        for(int i=0;i<n;i++){
            mini=min(mini,usado[i]);
        }
        return mini;
    }
};