#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums){
        vector<int> res;
        sort(nums.begin(),nums.end());
        int now=nums[0];
        for(auto &u:nums){
            while(now<u)res.push_back(now++);
            now++;
        }
        return res;
    }
};