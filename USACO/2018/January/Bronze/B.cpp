#include <bits/stdc++.h>
using namespace std;
int n,psum[1000],con,mini=1e9;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("lifeguards.in","r",stdin);
    freopen("lifeguards.out","w",stdout);
    cin >> n;
    pair<int,int> nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i].first >> nums[i].second;
        psum[--nums[i].first]++;
        psum[--nums[i].second]--;
    }
    if(psum[0])con++;
    for(int i=1;i<1000;i++)if(psum[i]+=psum[i-1])con++;
    for(int i=0;i<n;i++){
        int now=0;
        for(int j=nums[i].first;j<nums[i].second;j++){
            if(psum[j]==1)now++;
        }
        mini=min(mini,now);
    }
    cout << con-mini;
}