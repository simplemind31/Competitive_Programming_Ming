#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices){
        int mini=1e9,res=0;
        for(int u:prices){
            res=max(res,u-mini);
            mini=min(mini,u);
        }
        return res;
    }
};