#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasSameDigits(string s){
        while(s.size()>2){
            string nu(s.size()-1,' ');
            for(int i=1;i<s.size();i++){
                nu[i-1]=(s[i-1]-48+s[i]-48)%10;
            }
            s=nu;
            nu="";
        }
        return s[0]==s[1];
    }
};