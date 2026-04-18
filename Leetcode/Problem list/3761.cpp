#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums){
        int n=nums.size();
        unordered_map<int,int> last;
        int res=1e9;
        for(int i=n-1;i>=0;i--){
            string st=to_string(nums[i]);
            reverse(st.begin(),st.end());
            int nue=stoi(st);
            if(last.count(nue))res=min(res,last[nue]-i);
            last[nums[i]]=i;
        }
        if(res==1e9)res=-1;
        return res;
    }
};