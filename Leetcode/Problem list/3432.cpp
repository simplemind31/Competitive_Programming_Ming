#include <bits/stdc++.h>
using namespace std;
short n,sum;
class Solution{
public:
    int countPartitions(vector<int>& nums){
        n=nums.size();
        for(int i=sum=0;i<n;i++)sum+=nums[i];
        return (sum%2)?0:(n-1);
    }
};