#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target){
        int n=nums.size();
        vector<int> res(n,-1e9);
        res[n-1]=0;
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(abs(nums[i]-nums[j])<=target)res[i]=max(res[i],res[j]+1);
            }
        }
        if(res[0]<0)res[0]=-1;
        return res[0];
    }
};