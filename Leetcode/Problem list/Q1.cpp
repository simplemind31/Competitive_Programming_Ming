#include <bits/stdc++.h>
using namespace std;
int n;
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums){
        nums.resize(2*(n=nums.size()));
        for(int i=0;i<n;i++)nums[i+n]=nums[i];
        return nums;
    }
};