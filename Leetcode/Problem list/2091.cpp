#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeletions(vector<int>& nums){
        int n=nums.size(),mini=0,maxi=0;
        if(n==1)return 1;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[mini])mini=i;
            else if(nums[i]>nums[maxi])maxi=i;
        }
        if(mini>maxi)swap(mini,maxi);
        return min({mini+1+n-maxi,maxi+1,n-mini});
    }
};