#include <bits/stdc++.h>
using namespace std;
int n,nums[200002],maxiiz[200002],maxide[200002],dp[200002],maxi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    nums[0]=nums[n+1]=2e9;
    vector<pair<int,int>> ord(n);
    for(int i=1;i<=n;i++){
        cin >> nums[i];
        ord[i-1]={nums[i],i};
    }
    sort(ord.begin(),ord.end());
    stack<int> ayu;
    ayu.push(0);
    for(int i=1;i<=n;i++){
        while(nums[i]>=nums[ayu.top()])ayu.pop();
        maxiiz[i]=ayu.top();
        ayu.push(i);
    }
    while(!ayu.empty())ayu.pop();
    ayu.push(n+1);
    for(int i=n;i>=1;i--){
        while(nums[i]>=nums[ayu.top()])ayu.pop();
        maxide[i]=ayu.top();
        ayu.push(i);
    }
    for(int i=0;i<n;i++){
        dp[maxiiz[ord[i].second]]=max(dp[maxiiz[ord[i].second]],dp[ord[i].second]+1);
        dp[maxide[ord[i].second]]=max(dp[maxide[ord[i].second]],dp[ord[i].second]+1);
    }
    for(int i=1;i<=n;i++){
        maxi=max(maxi,dp[i]);
    }
    cout << maxi+1;
}