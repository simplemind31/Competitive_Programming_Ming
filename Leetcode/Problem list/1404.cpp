#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSteps(string s){
        bool xd=false;
        int can=0;
        for(int i=s.size()-1;i>=1;i--){
            can++;
            if(!xd && s[i]=='1'){
                xd=true;
                can++;
            }
            if(xd && s[i]=='0'){
                can++;
            }
        }
        if(xd)can++;
        return can;
    }
};