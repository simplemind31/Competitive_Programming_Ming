#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    vector<int> nums;
    vector<vector<vector<int>>> dp; 
    int solve(int pos,int M,bool alice){
        if(pos==n)return 0;
        if(dp[pos][M][alice])return dp[pos][M][alice];
        if(!alice)dp[pos][M][alice]=1e9;
        int suma=0;
        for(int i=pos;i<min(pos+M,n);i++){
            suma+=nums[i];
            if(alice)dp[pos][M][alice]=max(dp[pos][M][alice],suma+solve(i+1,min(max(M,2*(i-pos+1)),n),!alice));
            else dp[pos][M][alice]=min(dp[pos][M][alice],solve(i+1,min(max(M,2*(i-pos+1)),n),!alice));
        }
        return dp[pos][M][alice];
    }
    int stoneGameII(vector<int>& piles){
        n=piles.size();
        nums=piles;
        dp.assign(n,vector(n+1,vector<int>(2)));
        return solve(0,min(2,n),1);
    }
};