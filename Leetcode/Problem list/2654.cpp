#include <bits/stdc++.h>
using namespace std;
int one,mcd,n;
class Solution{
public:
    int minOperations(vector<int>& nums){
        one=mcd=0;
        n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                one++;
            }
        }
        if(one)return n-one;
        for(int i=0;i<n;i++)mcd=__gcd(mcd,nums[i]);
        if(mcd>1)return -1;
        one=n;
        for(int i=0;i<n;i++){
            mcd=nums[i];
            for(int j=i+1;j<n;j++){
                mcd=__gcd(mcd,nums[j]);
                if(mcd==1){
                    one=min(one,j-i+1);
                    break;
                }
            }
        }
        return n-1+one-1;
    }
};