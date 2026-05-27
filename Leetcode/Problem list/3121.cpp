#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSpecialChars(string word){
        int res=0,con1=0,con2=0,imposi=0;
        for(char u:word){
            if(u<='Z')con2|=1<<(u-'A');
            else{
                if(con2&(1<<(u-'a')))imposi|=1<<(u-'a');
                else con1|=1<<(u-'a');
            }
        }
        return __builtin_popcount((con1&con2)&(~imposi));
    }
};