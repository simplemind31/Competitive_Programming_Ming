#include <bits/stdc++.h>
using namespace std;
int n,k,res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    k=n-k;
    int nums[n];
    for(int i=0;i<n;i++)cin >> nums[i];
    sort(nums,nums+n);
    deque<int> mono;
    for(int i=1;i<k;i++){
        while(!mono.empty() && nums[i]-nums[i-1]<=nums[mono.back()]-nums[mono.back()-1])mono.pop_back();
        mono.push_back(i);
    }
    res=nums[k-1]-nums[0]+nums[mono.front()]-nums[mono.front()-1];
    for(int i=k;i<n;i++){
        while(!mono.empty() && nums[i]-nums[i-1]<=nums[mono.back()]-nums[mono.back()-1])mono.pop_back();
        mono.push_back(i);
        while(mono.front()<=i-k+1)mono.pop_front();
        res=min(res,nums[i]-nums[i-k+1]+nums[mono.front()]-nums[mono.front()-1]);
    }
    cout << res;
}
//2 2 8 10 17 17