#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool judgeCircle(string moves) {
        int a=0,b=0;
        for(auto u:moves){
            if(u=='L')a--;
            else if(u=='R')a++;
            else if(u=='U')b++;
            else b--;
        }
        return a==0 && b==0;
    }
};