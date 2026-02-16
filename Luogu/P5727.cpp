#include <bits/stdc++.h>
using namespace std;
int a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    vector<int> nums;
    cin >> a;
    while(a!=1){
        nums.push_back(a);
        if(a&1)a=a*3+1;
        else a/=2;
    }
    nums.push_back(1);
    reverse(nums.begin(),nums.end());
    for(auto u:nums)cout << u << ' ';
}