#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool xd;
    char mini,con;
    int sum;
    int minimumPairRemoval(vector<int>& nums){
        con=0;
        while(true && nums.size()>1){
            mini=nums.size()-2;
            xd=nums[mini]>nums[mini+1];
            for(char i=mini-1;i>=0;i--){
                xd|=nums[i]>nums[i+1];
                if(nums[i]+nums[i+1]<=nums[mini]+nums[mini+1])mini=i;
            }
            if(!xd)break;
            sum=nums[mini]+nums[mini+1];
            for(char j=0;j<2;j++)nums.erase(nums.begin()+mini);
            nums.insert(nums.begin()+mini,sum);
            con++;
        }
        return con;
    }
};