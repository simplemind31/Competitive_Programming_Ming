#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res=1e9,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target)res=min(res,abs(i-start));
        }
        return res;
    }
};