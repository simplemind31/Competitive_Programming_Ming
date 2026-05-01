#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums){
        int n=nums.size();
        ll sumnow=0,sum=0,maxi=-2e9;
        for(int i=0;i<n;i++){
            sumnow+=i*nums[i];
            sum+=nums[i];
        }
        for(int i=n-1;i>=0;i--)maxi=max(maxi,sumnow+=sum-n*nums[i]);
        return maxi;
    }
};