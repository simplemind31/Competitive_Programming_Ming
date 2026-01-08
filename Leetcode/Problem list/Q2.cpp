#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n){
        vector<int> res(2*n);
        int j=0;
        for(int i=0;i<2*n;i+=2){
            res[i]=nums[j];
            res[i+1]=nums[j+(n)];
            j++;
        }
        return res;
    }
};