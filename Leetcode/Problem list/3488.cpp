#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries){
        int n=nums.size(),q=queries.size();
        map<int,vector<int>> ap;
        for(int i=0;i<n;i++)ap[--nums[i]].push_back(i);
        vector<int> res(q,1e9);
        for(int i=0;i<q;i++){
            if(ap[nums[queries[i]]].size()==1){
                res[i]=-1;
                continue;
            }
            int de=upper_bound(ALL(ap[nums[queries[i]]]),queries[i])-ap[nums[queries[i]]].begin();
            int iz=lower_bound(ALL(ap[nums[queries[i]]]),queries[i])-ap[nums[queries[i]]].begin()-1;
            //cout << de << ' ';
            if(de==ap[nums[queries[i]]].size())de=0;
            if(iz==-1)iz=ap[nums[queries[i]]].size()-1;
            res[i]=min((ap[nums[queries[i]]][de]-queries[i]+n)%n,(-ap[nums[queries[i]]][iz]+queries[i]+n)%n);
        }
        return res;
    }
};