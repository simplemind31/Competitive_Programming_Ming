#include <bits/stdc++.h>
using namespace std;
short con;
class Solution {
public:
    int minimumOperations(vector<int>& nums){
        con=0;
        for(short u:nums)con+=(u%3>0);
        return con;
    }
};