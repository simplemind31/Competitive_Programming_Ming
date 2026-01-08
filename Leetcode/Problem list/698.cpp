#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool calc(vector<int>& nums, int sumanow,int position,int prom,vector<bool>& temp,int k){
        int N=nums.size();
        if(sumanow==prom){
            vector<int> tempora;
            for(int i=0;i<N;i++){
                if(!temp[i]){
                    tempora.push_back(nums[i]);
                }
            }
            if(canPartitionKSubsets(tempora,k-1)){
                return true;
            }
            return false;
        }
        if(position>=N)return false;
        if(sumanow+nums[position]<=prom){
            temp[position]=true;
            if(calc(nums,sumanow+nums[position],position+1,prom,temp,k)){
                temp[position]=false;
                return true;
            }
            temp[position]=false;
        }
        return calc(nums,sumanow,position+1,prom,temp,k);
    }
    bool canPartitionKSubsets(vector<int>& nums, int k){
        if(k==0 && nums.empty()){
            return true;
        }
        vector<bool> temp;
        int N=nums.size();
        sort(nums.rbegin(),nums.rend());
        temp.assign(N,false);
        int sum=0;
        for(int i=0;i<N;i++)sum+=nums[i];
        int prom=sum/k;
        if(prom*k!=sum)return false;
        return calc(nums,0,0,prom,temp,k);
    }
};
int main(){
    Solution nose;
    vector<int> aaa={4,5,9,3,10,2,10,7,10,8,5,9,4,6,4,9};
    cout << nose.canPartitionKSubsets(aaa,5);
}