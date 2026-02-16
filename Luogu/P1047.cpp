#include <bits/stdc++.h>
using namespace std;
int l,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    vector<pair<int,int>> nums;
    cin >> l >> m;
    pair<int,int> temp[m];
    for(int i=0;i<m;i++)cin >> temp[i].first >> temp[i].second;
    sort(temp,temp+m);
    nums.push_back(temp[0]);
    for(int i=0;i<m;i++){
        if(nums.back().second>=temp[i].first)nums.back().second=max(nums.back().second,temp[i].second);
        else nums.push_back(temp[i]);
    }
    for(auto u:nums)l-=u.second-u.first+1;
    cout << l+1;
}