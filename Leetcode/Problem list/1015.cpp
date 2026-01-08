#include <bits/stdc++.h>
using namespace std;
int sobra;
class Solution {
public:
    int smallestRepunitDivByK(int k){
        if(k%10==5 || k%2==(sobra=0))return -1;
        for(int i=1;i<=200000;i++)if((sobra=(sobra*10+1)%k)==0)return i;
        return -1;
    }
};