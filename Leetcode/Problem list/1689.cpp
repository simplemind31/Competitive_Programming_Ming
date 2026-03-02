#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPartitions(string n){
        int maxi=0;
        for(auto u:n)maxi=max(u-'0',maxi);
        return maxi;
    }
};