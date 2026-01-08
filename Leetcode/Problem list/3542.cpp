#include <bits/stdc++.h>
using namespace std;
int res,n,mini;
class Solution {
public:
    int minOperations(vector<int>& nums){
        res=0;
        stack<int> ay;
        n=nums.size();
        for(int i=0;i<n;i++){
            while(!ay.empty()){
                if(ay.top()==nums[i]){
                    ay.pop();
                }else if(nums[i]<ay.top()){
                    res++;
                    ay.pop();
                }else{
                    break;
                }
            }
            ay.push(nums[i]);
        }
        while(!ay.empty()){
            if(ay.top()==0){
                ay.pop();
            }else{
                ay.pop();
                res++;
            }
        }
        return res;
    }
};