#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
int n,l;
class Solution {
public:
    int countPartitions(vector<int>& nums,int k){
        n=nums.size();
        int dp[n],sum[n];
        multiset<int> help;
        help.insert(nums[l=0]);
        for(int i=dp[0]=sum[0]=1;i<n;i++){
            help.insert(nums[i]);
            while((nums[i]-*help.begin()>k) || (*(--help.end())-nums[i]>k))help.erase(help.find(nums[l++]));
            dp[i]=sum[i-1];
            if(l-2>=0)dp[i]-=sum[l-2];
            if(l==0)dp[i]++;
            dp[i]=(dp[i]%MOD+MOD)%MOD;
            sum[i]=(sum[i-1]+dp[i])%MOD;
        }
        return dp[n-1];
    }
};