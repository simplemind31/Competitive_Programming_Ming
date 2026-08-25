#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int maxProduct(vector<int>& nums){
        int maxi=0,now=0;
        for(auto u:nums){
            maxi=max(now*(u-1),maxi);
            now=max(now,u-1);
        }
        return maxi;
    }
};