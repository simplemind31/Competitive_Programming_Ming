#include <bits/stdc++.h>
using namespace std;
int t,n,k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        int nums[n];
        pair<pair<int,int>,int> restric[k];
        for(int i=0;i<n;i++){
            cin >> nums[i];
        }
        sort(nums,nums+n);
        for(int i=0;i<k;i++)cin >> restric[i].first.first >> restric[i].first.second >> restric[i].second;
        sort(restric,restric+k);
        int last=0;
        priority_queue<pair<int,int>> ord;
        // valor, indice
        for(int i=0;i<n;i++){
            while(!ord.empty() && restric[ord.top().second].first.second<nums[i])ord.pop();
            for(;last<k && restric[last].first.first<=nums[i];last++){
                ord.push({restric[last].second,last});
            }
        }
    }
}