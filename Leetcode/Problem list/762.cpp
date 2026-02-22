#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPrimeSetBits(int left, int right){
        int con=0;
        vector<bool> p(32);
        p[2]=p[3]=p[5]=p[7]=p[11]=p[13]=p[17]=p[19]=p[23]=p[29]=p[31]=1;
        for(;left<=right;left++)con+=p[__builtin_popcount(left)];
        return con;
    }
};