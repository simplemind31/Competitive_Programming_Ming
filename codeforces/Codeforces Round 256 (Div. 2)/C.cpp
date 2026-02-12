#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
using namespace std;
int n,nums[5000];
int solve(int l,int r){
    if(l>r)return 0;
    int posmini=l;
    for(int i=l;i<=r;i++)if(nums[i]<nums[posmini])posmini=i;
    int a=nums[posmini];
    for(int i=l;i<=r;i++)nums[i]-=a;
    return min(r-l+1,solve(l,posmini-1)+a+solve(posmini+1,r));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)cin >> nums[i];
    cout << solve(0,n-1);
}