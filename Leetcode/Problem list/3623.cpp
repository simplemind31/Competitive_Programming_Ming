#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long res,acum;
class Solution{
public:
    int countTrapezoids(vector<vector<int>>& points){
        unordered_map<int,long long> con;
        res=acum=0;
        for(auto u:points)con[u[1]]++;
        for(auto u:con){
            res+=acum*u.second*(u.second-1)/2;
            acum+=u.second*(u.second-1)/2;
            res%=MOD;
            acum%=MOD;
        }
        return res;
    }
};