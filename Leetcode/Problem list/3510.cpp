#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums){
        ll con=0,n=nums.size(),res=0;
        set<pair<ll,ll>> numeros;
        set<pair<ll,ll>> orden;
        numeros.insert({0,nums[0]});
        for(ll i=1;i<n;i++){
            if(nums[i-1]>nums[i])con++;
            numeros.insert({i,nums[i]});
            orden.insert({nums[i-1]+nums[i],i-1});
        }
        while(con){
            // unir el top con siguiente
            auto p=numeros.lower_bound({orden.begin()->second,-1e18});
            vector<pair<ll,ll>> ordborr,ordins,numsborr,numsins;
            if(p!=numeros.begin()){
                //tiene anterior
                auto an=p;
                an--;
                if(an->second>p->second)con--;
                if(an->second>orden.begin()->first)con++;
                ordborr.push_back({an->second+p->second,an->first});
                ordins.push_back({an->second+orden.begin()->first,an->first});
            }
            auto ne=p;
            ne++;
            if(p->second>ne->second)con--;
            auto ne2=ne;
            ne2++;
            if(ne2!=numeros.end()){
                if(ne->second>ne2->second)con--;
                if(orden.begin()->first>ne2->second)con++;
                ordborr.push_back({ne->second+ne2->second,ne->first});
                ordins.push_back({orden.begin()->first+ne2->second,p->first});
            }
            numsborr.push_back(*ne);
            numsborr.push_back(*p);
            numsins.push_back({orden.begin()->second,orden.begin()->first});
            ordborr.push_back(*orden.begin());
            res++;
            for(auto u:ordborr)orden.erase(u);
            for(auto u:ordins)orden.insert(u);
            for(auto u:numsborr)numeros.erase(u);
            for(auto u:numsins)numeros.insert(u);
        }
        return res;
    }
};