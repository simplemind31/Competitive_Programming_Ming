#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,n,k,a;
int val(int x,int y){
    return ((~(x^y))&((1<<k)-1));
}
pair<pair<int,int>,pair<int,int>> solve(vector<pair<int,int>>& nums,int pos){
    if(nums.size()<=1){
        return {{0,-1},{(1<<k)-1,-1}};
    }
    if(nums.size()==2 || pos<0){
        return {nums[0],nums[1]};
    }
    vector<pair<int,int>> one,zero;
    for(auto u:nums){
        if(u.first&(1<<pos))one.push_back(u);
        else zero.push_back(u);
    }
    pair<pair<int,int>,pair<int,int>> op1=solve(one,pos-1),op2=solve(zero,pos-1);
    if(op1.first.second==-1)return op2;
    if(op2.first.second==-1)return op1;
    if(val(op1.first.first,op1.second.first)>=val(op2.first.first,op2.second.first))return op1;
    else return op2;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<pair<int,int>> nums;
        for(int i=0;i<n;i++){
            cin >> a;
            nums.push_back({a,i+1});
        }
        pair<pair<int,int>,pair<int,int>> res=solve(nums,k-1);
        cout << res.first.second << ' ' << res.second.second << ' ' << ((~res.first.first)&((1<<k)-1)) << '\n';
    }
}