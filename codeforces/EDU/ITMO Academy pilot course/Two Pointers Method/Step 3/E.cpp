#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    pair<int,int> nums[n];//w,c
    for(int i=0;i<n;i++)cin >> nums[i].first;
    for(int i=0;i<n;i++)cin >> nums[i].second;
    int j=0;
    ll w=0,c=0,maxi=0;
    for(int i=0;i<n;i++){
        w+=nums[i].first;
        c+=nums[i].second;
        while(w>k){
            w-=nums[j].first;
            c-=nums[j++].second;
        }
        maxi=max(maxi,c);
    }
    cout << maxi;
}