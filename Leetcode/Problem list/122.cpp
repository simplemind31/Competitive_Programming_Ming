#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices){
        int last=1e9,res=0;
        for(int u:prices){
            if(u>last)res+=u-last;
            last=u;
        }
        return res;
    }
};