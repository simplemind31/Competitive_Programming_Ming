#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini=1000,maxi=1;
        for(auto &u:nums){
            mini=min(mini,u);
            maxi=max(maxi,u);
        }
        return gcd(mini,maxi);
    }
};