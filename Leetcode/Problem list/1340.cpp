#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dp;
    vector<int>* A;
    int lim,n,maxi;
    void solve(int pos){
        if(dp[pos]!=-1)return;
        int maxi=0;
        dp[pos]=1;
        for(int i=pos-1;i>=max(pos-lim,0) && (*A)[i]<(*A)[pos];i--){
            if((*A)[i]<maxi)continue;
            maxi=(*A)[i];
            solve(i);
            dp[pos]=max(dp[pos],1+dp[i]);
        }
        maxi=0;
        for(int i=pos+1;i<=min(pos+lim,n-1) && (*A)[i]<(*A)[pos];i++){
            if((*A)[i]<maxi)continue;
            maxi=(*A)[i];
            solve(i);
            dp[pos]=max(dp[pos],1+dp[i]);
        }
    }
    int maxJumps(vector<int>& arr,int d){
        lim=d;
        n=arr.size();
        maxi=0;
        A=&arr;
        dp.assign(n,-1);
        for(int i=0;i<n;i++){
            solve(i);
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};