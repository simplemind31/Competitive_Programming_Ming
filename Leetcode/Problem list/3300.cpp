#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int minElement(vector<int>& nums){
        short mini=50;
        for(auto& u:nums){
            short sum=0;
            while(u){
                sum+=u%10;
                u/=10;
            }
            mini=min(mini,sum);
        }
        return mini;
    }
};