#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums){
        int n=nums.size(),res=0,maxi=0;
        for(int i=0;i<n;i++)maxi=max(maxi,nums[i]);
        int need=32-__builtin_clz(maxi);
        vector<bool> A(1<<need),B(1<<need);
        A[0]=1;
        for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)A[nums[i]^nums[j]]=1;
        for(int i=0;i<(1<<need);i++){
            if(A[i])for(int j=0;j<n;j++)B[nums[j]^i]=1;
        }
        for(int i=0;i<(1<<need);i++)res+=B[i];
        return res;
    }
};