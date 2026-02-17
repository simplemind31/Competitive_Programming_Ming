#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverseBits(int n){
        int num=0;
        for(int i=0;i<32;i++){
            num<<=1;
            num+=n&1;
            n>>=1;
        }
        return num;
    }
};