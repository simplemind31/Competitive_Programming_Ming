#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll maxi,minitemp;
int n;
class Solution {
public:
    ll maxSubarraySum(vector<int>& nums, int k){
        maxi=-1e18;
        vector<ll>psum((n=nums.size())+1);
        for(int i=1;i<=n;i++)psum[i]=nums[i-1]+psum[i-1];
        for(int i=1;i<=k;i++){
            minitemp=psum[i-1];
            for(int j=i+k-1;j<=n;j+=k){
                maxi=max(maxi,psum[j]-minitemp);
                minitemp=min(minitemp,psum[j]);
            }
        }
        return maxi;
    }
};