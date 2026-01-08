#include <bits/stdc++.h>
using namespace std;
int maxi,n;
class Solution {
public:
    int maximumGap(vector<int>& nums){
        sort(nums.begin(),nums.end());
        n=nums.size();
        for(int i=maxi=0;i<n-1;i++)maxi=max(maxi,nums[i+1]-nums[i]);
        return maxi;
    }
};