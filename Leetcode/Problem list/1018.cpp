#include <bits/stdc++.h>
using namespace std;
int now,n;
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums){
        vector<bool> res(n=nums.size());
        for(int i=now=0;i<n;i++)res[i]=(2*(now=(2*now+nums[i])%10)%10==0);
        return res;
    }
};