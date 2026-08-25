#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int maximumProduct(vector<int>& nums){
        if(nums.size()==3)return nums[0]*nums[1]*nums[2];
        bool xd=false;
        int pos[3]={0,0,0},nega[3]={0,0,0},nega2[3]={(int)-1e9,(int)-1e9,(int)-1e9};
        for(auto &u:nums){
            int cop=u;
            if(u>=0)xd=1;
            for(int j=0;j<3;j++){
                if(u>pos[j])swap(u,pos[j]);
                if(u<nega[j])swap(u,nega[j]);
                if(cop>nega2[j])swap(cop,nega2[j]);
            }
        }
        if(xd)return max(pos[0]*pos[1]*pos[2],nega[0]*nega[1]*pos[0]);
        return nega2[0]*nega2[1]*nega2[2];
    }
};