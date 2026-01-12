#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points){
        short n=points.size();
        int res=0;
        for(short i=1;i<n;i++)res+=max(abs(points[i][0]-points[i-1][0]),abs(points[i][1]-points[i-1][1]));
        return res;
    }
};