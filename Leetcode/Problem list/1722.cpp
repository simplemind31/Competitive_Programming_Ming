#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct DSU{
        vector<int> tam,pad;
        int find(int x){return x==pad[x]?x:pad[x]=find(pad[x]);}
        bool unite(int x,int y){
            if((x=find(x))==(y=find(y)))return false;
            if(tam[x]<tam[y])swap(x,y);
            tam[pad[y]=x]+=tam[y];
            return true;
        }
        DSU(int x){
            tam.resize(x);
            pad.resize(x);
            for(int i=0;i<x;i++)tam[pad[i]=i]=1;
        }
    };
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        DSU clav(n);
        for(auto u:allowedSwaps)clav.unite(u[0],u[1]);
        vector<map<int,int>> tot(n);
        for(int i=0;i<n;i++){
            tot[clav.find(i)][source[i]]++;
            tot[clav.find(i)][target[i]]--;
        }
        int res=0;
        for(int i=0;i<n;i++){
            for(auto u:tot[i]){
                res+=abs(u.second);
            }
        }
        return res/2;
    }
};