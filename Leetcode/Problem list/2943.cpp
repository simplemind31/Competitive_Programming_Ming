#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(ALL(hBars));
        sort(ALL(vBars));
        int maxih=2,maxiv=2,now=1;
        n=hBars.size();
        m=vBars.size();
        for(int i=1;i<n;i++){
            if(hBars[i-1]==hBars[i]-1)now++;
            else now=1;
            maxih=max(maxih,now+1);
        }
        now=1;
        for(int i=1;i<m;i++){
            if(vBars[i-1]==vBars[i]-1)now++;
            else now=1;
            maxiv=max(maxiv,now+1);
        }
        maxih=min(maxih,maxiv);
        return maxih*maxih;
    }
};