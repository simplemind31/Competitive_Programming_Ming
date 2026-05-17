#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMoves(vector<int>& nums, int limit){
        int n=nums.size();
        vector<int> res(2*limit+2);
        res[2]+=n;
        for(int i=0;i<n/2;i++){
            res[min(nums[i],nums[n-i-1])+1]--;
            res[nums[i]+nums[n-i-1]]--;
            res[nums[i]+nums[n-i-1]+1]++;
            res[max(nums[i],nums[n-i-1])+limit+1]++;
        }
        int mini=1e9,now=0;
        for(int i=2;i<=2*limit;i++){
            now+=res[i];
            mini=min(mini,now);
        }
        return mini;
    }
};