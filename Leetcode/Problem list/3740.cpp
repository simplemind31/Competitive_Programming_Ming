#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDistance(vector<int>& nums){
        int n=nums.size();
        vector<pair<int,int>> con(n,{-1e9,-1e9});
        int res=1e9;
        for(int i=0;i<n;i++){
            nums[i]--;
            res=min(res,2*(i-con[nums[i]].first));
            con[nums[i]].first=con[nums[i]].second;
            con[nums[i]].second=i;
        }
        if(res==1e9)res=-1;
        return res;
    }
};