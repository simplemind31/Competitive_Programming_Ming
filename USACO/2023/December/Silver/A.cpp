#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
ll con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    pair<int,int> nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i].first >> nums[i].second;
    }
    sort(nums,nums+n);
    reverse(nums,nums+n);
    deque<pair<int,int>> ord;
    ord.push_back({2e9,m});
    for(int i=0;i<n;i++){
        ll now=0;
        while(nums[i].second && !ord.empty()){
            pair<int,int> top=ord.front();
            ord.pop_front();
            if(top.first>=nums[i].first+k){
                int mini=min(top.second,nums[i].second);
                now+=mini;
                nums[i].second-=mini;
                top.second-=mini;
            }else{
                nums[i].second=0;
            }
            if(top.second)ord.push_front(top);
        }
        if(now)ord.push_back({nums[i].first,now});
        con+=now;
    }
    cout << con;
}