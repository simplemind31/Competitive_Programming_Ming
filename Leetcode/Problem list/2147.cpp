#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
class Solution {
public:
    int numberOfWays(string corridor){
        vector<int> poss;
        for(int i=0;i<corridor.size();i++)if(corridor[i]=='S')poss.push_back(i);
        if(poss.size()%2 || poss.empty())return 0;
        ll res=1;
        for(int i=2;i<poss.size();i+=2){
            res*=poss[i]-poss[i-1];
            res%=MOD;
        }
        return res;
    }
};