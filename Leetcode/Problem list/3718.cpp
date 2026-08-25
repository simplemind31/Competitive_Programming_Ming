#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        bitset<101> con;
        for(auto u:nums)if(u%k==0)con[u/k]=1;
        for(int i=1;i<=100;i++)if(!con[i])return i*k;
        return 101*k;
    }
};