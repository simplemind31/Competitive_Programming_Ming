#include <bits/stdc++.h>
using namespace std;
long long sum;
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries){
        sort(batteries.rbegin(),batteries.rend());
        sum=0;
        for(int i=n;i<batteries.size();i++)sum+=batteries[i];
        for(int i=n-1;i>=1;i--){
            if(sum>=(n-i)*(batteries[i-1]-batteries[i]))sum-=(n-i)*(batteries[i-1]-batteries[i]);
            else return batteries[i]+sum/(n-i);
        }
        return batteries[0]+sum/n;
    }
};