#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumPushes(string word){
        short res=0,n=word.size();
        for(int i=1;i<=4;i++){
            res+=i*min(n,(short)8);
            n=max(0,n-8);
        }
        return res;
    }
};