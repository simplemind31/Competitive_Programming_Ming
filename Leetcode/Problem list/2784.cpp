#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isGood(vector<int>& nums){
        int n=nums.size()-1;
        vector<int> con(n+1);
        for(int i=0;i<n+1;i++){
            if(nums[i]>n)return false;
            con[nums[i]]++;
            if(con[nums[i]]==3)return false;
            if(con[nums[i]]==2 && nums[i]!=n)return false;
        }
        return true;
    }
};