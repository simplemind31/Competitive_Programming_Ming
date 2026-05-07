#include <bits/stdc++.h>
using namespace std;
struct DSU{
    int n;
    vector<int> tam,pad,maxi;
    int find(int x){return x==pad[x]?x:pad[x]=find(pad[x]);}
    bool unite(int x,int y){
        if((x=find(x))==(y=find(y)))return false;
        if(tam[x]<tam[y])swap(x,y);
        tam[pad[y]=x]+=tam[y];
        maxi[x]=max(maxi[x],maxi[y]);
        return true;
    }
    DSU(vector<int> x){
        n=x.size();
        tam.assign(n,1);
        pad=maxi=tam;
        for(int i=0;i<n;i++)maxi[i]=x[pad[i]=i];
    }
};
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        stack<int> pila;
        int n=nums.size();
        DSU clav(nums);
        for(int i=0;i<n;i++){
            while(!pila.empty() && nums[i]<clav.maxi[clav.find(pila.top())]){
                clav.unite(i,pila.top());
                pila.pop();
            }
            pila.push(i);
        }
        vector<int> res(n);
        for(int i=0;i<n;i++){
            res[i]=clav.maxi[clav.find(i)];
        }
        return res;
    }
};