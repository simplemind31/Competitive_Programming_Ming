#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int s,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> s >> n;
    vector<pair<int,int>> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i].first >> nums[i].second;
    }
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(s<=nums[i].first){
            cout << "NO";
            return 0;
        }
        s=min(1000000,s+nums[i].second);
    }
    cout << "YES";
}