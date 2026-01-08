#include <bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        vector<pair<int,int>> nums(n);
        for(int i=0;i<n;i++){
            cin >> nums[i].first;
        }
        for(int i=0;i<n;i++){
            cin >> nums[i].second;
        }
        sort(nums.begin(),nums.end());
        int maxi=nums[0].second;
        bool xd=true;
        for(int i=1;i<n;i++){
            if(nums[i].first==nums[i-1].first || nums[i-1].second>=nums[i].second){
                xd=false;
                break;
            }
        }
        if(xd)cout << "YES\n";
        else cout << "NO\n";
    }
}