#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums){
        int n;
        vector<int> res(n=nums.size());
        for(int i=0;i<n;i++){
            if(nums[i]==2)res[i]=-1;
            else res[i]=nums[i]-(((-(nums[i]+1))&(nums[i]+1))>>1);
        }
        return res;
    }
};