#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binaryGap(int n){
        int last=1e9,maxi=0;
        for(int i=0;i<31;i++){
            if(n&(1<<i)){
                maxi=max(maxi,i-last);
                last=i;
            }
        }
        return maxi;
    }
};