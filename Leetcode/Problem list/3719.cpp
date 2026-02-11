#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestBalanced(vector<int>& nums){
        int res=0;
        for(int i=0,n=nums.size();i<n;i++){
            set<int> par,impar;
            for(int j=i;j<n;j++){
                if(nums[j]&1)impar.insert(nums[j]);
                else par.insert(nums[j]);
                if(par.size()==impar.size())res=max(res,j-i+1);
            }
        }
        return res;
    }
};