#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minRemoval(vector<int>& nums, int k){
        int mini=1e9,j=0;
        sort(nums.begin(),nums.end());
        for(int i=0,n=nums.size();i<n;i++){
            while(1ll*nums[j]*k<1ll*nums[i])j++;
            mini=min(mini,j+n-i-1);
            if(1ll*nums[j]*k>=1e9){
                mini=min(mini,j);
                break;
            }
        }
        return mini;
    }
};