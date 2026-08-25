#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    ll gcdSum(vector<int>& nums){
        int maxi=0,n=nums.size();
        ll res=0;
        for(auto &u:nums){
            maxi=max(maxi,u);
            u=gcd(u,maxi);
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n/2;i++)res+=gcd(nums[i],nums[n-1-i]);
        return res;
    }
};