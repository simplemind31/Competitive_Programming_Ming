#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums){
        int minipos=0,n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<nums[minipos])minipos=i;
            else if(nums[i]==nums[minipos] && nums[i]<nums[i-1])minipos=i;
        }
        for(int i=(minipos+1)%n;i!=minipos;i=(i+1)%n)if(nums[i]<nums[(i-1+n)%n])return false;
        return true;
    }
};