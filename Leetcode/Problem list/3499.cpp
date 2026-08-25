#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int maxActiveSectionsAfterTrade(string s){
        int n=s.size(),maxi=0,tot=0;
        vector<int> nums;
        if(s[0]=='0')nums.push_back(0);
        nums.push_back(1);
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1])nums.back()++;
            else nums.push_back(1);
        }
        if(s[n-1]=='0')nums.push_back(0);
        // max 010
        // max 10
        n=nums.size();
        for(int i=0;i<n;i+=2){
            tot+=nums[i];
            if(i)maxi=max(maxi,nums[i-1]+nums[i+1]);
        }
        return maxi+tot;
    }
};