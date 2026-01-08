#include <bits/stdc++.h>
using namespace std;
int n;
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits){
        if((n=bits.size())==1)return true;
        if(bits[n-2]==0)return true;
        for(int i=0;i<=n-3;i++)if(bits[i])if(i++>n-4)return true;
        return false;
    }
};