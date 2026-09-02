#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums,int limit){
        int n=nums.size(),last=0;
        vector<int> res(n);
        vector<pair<int,int>> ord(n+1);
        for(int i=0;i<n;i++)ord[i]={nums[i],i};
        ord[n]={2e9+7,1e9};
        sort(ord.begin(),ord.end());
        for(int i=1;i<=n;i++){
            if(ord[i].first-ord[i-1].first>limit){
                vector<int> posi;
                for(int j=last;j<=i-1;j++)posi.push_back(ord[j].second);
                sort(posi.begin(),posi.end());
                for(int j=0;j<=i-last-1;j++)res[posi[j]]=ord[last+j].first;
                last=i;
            }
        }
        return res;
    }
};