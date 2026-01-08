#include <bits/stdc++.h>
using namespace std;
bitset<1000> existe;
short n;
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        existe=0;
        n=nums.size();
        for(short i=0;i<n;i++)existe[nums[i]-1]=1;
        while(original<=1000 && existe[original-1])original*=2;
        return original;
    }
};