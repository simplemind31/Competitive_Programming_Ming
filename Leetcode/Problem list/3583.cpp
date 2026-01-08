#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
int n;
ll res;
class Solution {
public:
    int specialTriplets(vector<int>& nums){
        res=0;
        vector<int> con(1e5+1),tot(1e5+1);
        n=nums.size();
        for(int i=0;i<n;i++)con[nums[i]]++;
        tot=con;
        con.assign(1e5+1,0);
        for(int i=1;i<n-1;i++){
            con[nums[i-1]]++;
            if(2*nums[i]>1e5)continue;
            ll ante=con[2*nums[i]];
            ll desp=tot[2*nums[i]];
            desp-=ante;
            if(nums[i]==0)desp--;
            res+=ante*desp;
            res%=MOD;
        }
        return res;
    }
};