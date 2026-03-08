#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums){
        int n=nums.size();
        string st(n,'0');
        for(int i=0;i<n;i++)st[i]=1-nums[i][i]+2*'0';
        return st;
    }
};