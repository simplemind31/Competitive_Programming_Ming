#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubsequence(vector<int>& nums){
        int x=0;
        vector<int> nue;
        for(auto u:nums){
            if(u){
                nue.push_back(u);
                x^=u;
            }
        }
        if(nue.empty())return 0;
        if(x)return nums.size();
        else return nums.size()-1;
    }
};