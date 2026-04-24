#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    vector<ll> distance(vector<int>& nums){
        int n=nums.size(),tiempo=0;
        vector<ll> res(n);
        unordered_map<int,int> hasher;
        for(int i=0;i<n;i++){
            if(!hasher.count(nums[i]))hasher[nums[i]]=tiempo++;
            nums[i]=hasher[nums[i]];
        }
        vector<pair<ll,ll>> con(tiempo);
        for(int i=0;i<n;i++){
            if(con[nums[i]].second)res[i]+=i*con[nums[i]].second-con[nums[i]].first;
            con[nums[i]].second++;
            con[nums[i]].first+=i;
        }
        con.assign(tiempo,{0,0});
        for(int i=n-1;i>=0;i--){
            if(con[nums[i]].second)res[i]+=con[nums[i]].first-i*con[nums[i]].second;
            con[nums[i]].second++;
            con[nums[i]].first+=i;
        }
        return res;
    }
};