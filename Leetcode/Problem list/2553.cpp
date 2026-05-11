#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums){
        vector<int> res;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            while(nums[i]){
                res.push_back(nums[i]%10);
                nums[i]/=10;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};