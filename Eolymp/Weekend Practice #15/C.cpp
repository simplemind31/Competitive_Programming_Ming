#include <bits/stdc++.h>
using namespace std;
int t,n,a,maxi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> nums(n+1),psumn(n+1);
        nums[0]=1e9;
        for(int i=1;i<=n;i++){
            cin >> nums[i];
        }
        for(int i=1;i<=n;i++){
            cin >> a;
            nums[i]-=a;
            nums[i]+=n;
            psumn[i]=psumn[i-1]+(nums[i]==n);
        }
        maxi=psumn[n];
        vector<pair<int,int>> last(2*n+1,{-1,0});
        for(int i=1;i<=n;i++){
            if(nums[i]==n)continue;
            if(last[nums[i]]==make_pair(-1,0))last[nums[i]].first=i;
            last[nums[i]].second++;
            if(last[nums[i]].second<=psumn[i]-psumn[last[nums[i]].first-1]){
                last[nums[i]]={i,1};
            }
            maxi=max(maxi,psumn[last[nums[i]].first]+psumn[n]-psumn[i]+last[nums[i]].second);
        }
        cout << maxi << '\n';
    }
}