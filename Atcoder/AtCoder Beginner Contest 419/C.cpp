#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    pair<int,int> nums[n];
    for(int i=0;i<n;i++)cin >> nums[i].first >> nums[i].second;
    int l=0,r=1e9;
    while(l<r){
        int mid=(l+r)>>1;
        vector<int> rang={0,(int)1e9,0,(int)1e9};
        for(int i=0;i<n;i++){
            rang[0]=max(rang[0],nums[i].first-mid);
            rang[1]=min(rang[1],nums[i].first+mid);
            rang[2]=max(rang[2],nums[i].second-mid);
            rang[3]=min(rang[3],nums[i].second+mid);
        }
        if(rang[0]<=rang[1] && rang[2]<=rang[3])r=mid;
        else l=mid+1;
    }
    cout << l;
}