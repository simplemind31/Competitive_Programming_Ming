#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll res,last;
class Solution {
public:
    ll getDescentPeriods(vector<int>& prices){
        res=last=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]!=prices[i-1]-1){
                res+=(i-last)*(i-last+1)/2;
                last=i;
            }
        }
        res+=(prices.size()-last)*(prices.size()-last+1)/2;
        return res;
    }
};