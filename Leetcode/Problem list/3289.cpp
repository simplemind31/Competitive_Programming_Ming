#include <bits/stdc++.h>
using namespace std;
short a,b;
bitset<100> ay;
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums){
        ay=0;
        a=-1;
        b=nums.size();
        for(short i=0;i<b;i++){
            if(ay[nums[i]]){
                if(a==-1){
                    a=nums[i];
                }else{
                    b=nums[i];
                    break;
                }
            }
            ay[nums[i]]=1;
        }
        return {a,b};
    }
};