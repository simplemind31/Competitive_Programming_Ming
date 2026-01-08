#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,l,x;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> pares(1+(n=nums.size()-1));
        for(int i=l=0;i<=n;i++)pares[i]={nums[i],i};
        sort(ALL(pares));
        while(1){
            if((x=pares[l].first+pares[n].first)==target)return {pares[l].second,pares[n].second};
            if(x>target)n--;
            else l++;
        }
        return {};
    }
};