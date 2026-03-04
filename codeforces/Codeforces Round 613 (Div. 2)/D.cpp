#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n;
int solve(int pos,vector<int> nums){
    if(nums.size()==0 || pos<0)return 0;
    vector<int> iz,de;
    for(auto u:nums){
        if(u&(1<<pos))iz.push_back(u);
        else de.push_back(u);
    }
    if(iz.empty())return solve(pos-1,de);
    else if(de.empty())return solve(pos-1,iz);
    int a=solve(pos-1,iz),b=solve(pos-1,de);
    return (1<<pos)+min(a,b);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin >> nums[i];
    cout << solve(30,nums) << ' ';
}