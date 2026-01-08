#include <bits/stdc++.h>
using namespace std;
int sum;
class Solution {
public:
    int minOperations(vector<int>& nums, int k){
        for(int i=sum=0;i<nums.size();i++)sum+=nums[i];
        return sum%k;
    }
};