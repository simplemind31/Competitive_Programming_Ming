#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    char findKthBit(int n, int k){
        string res[20];
        res[0]="0";
        for(int i=1;i<n;i++){
            res[i]=res[i-1]+"1";
            reverse(res[i-1].begin(),res[i-1].end());
            for(int j=0;j<res[i-1].size();j++){
                res[i-1][j]=1-(res[i-1][j]-48)+48;
            }
            res[i]+=res[i-1];
        }
        return res[n-1][k-1];
    }
};