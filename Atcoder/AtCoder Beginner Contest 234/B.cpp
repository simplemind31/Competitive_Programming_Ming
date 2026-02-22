#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
double maxi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    pair<int,int> nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i].first >> nums[i].second;
        for(int j=0;j<i;j++){
            maxi=max(maxi,sqrt(pow(nums[i].first-nums[j].first,2)+pow(nums[i].second-nums[j].second,2)));
        }
    }
    cout << fixed << setprecision(6) << maxi;
}