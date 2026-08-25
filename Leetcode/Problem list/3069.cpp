#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> resultArray(vector<int>& nums){
        int n=nums.size();
        vector<int> ar1,ar2;
        ar1.push_back(nums[0]);
        ar2.push_back(nums[1]);
        for(int i=2;i<n;i++)(ar1.back()>ar2.back()?ar1:ar2).push_back(nums[i]);
        for(auto u:ar2)ar1.push_back(u);
        return ar1;
    }
};