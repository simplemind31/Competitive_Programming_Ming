#include <bits/stdc++.h>
using namespace std;
int n,last;
class Solution{
public:
    bool kLengthApart(vector<int>& nums, int k){
        last=-1;
        n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                if(last!=-1 && i-last-1<k)return false;
                last=i;
            }
        }
        return true;
    }
};