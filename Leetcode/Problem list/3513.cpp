#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums){
        int n=nums.size();
        return n<=1?1:n<=2?2:1<<32-__builtin_clz(n);
    }
};