#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(string s) {
        int con00=0,con01=0,con10=0,con11=0;
        for(int i=0;i<s.size();i++){
            if(i&1){
                if(s[i]-48)con11++;
                else con10++;
            }else{
                if(s[i]-48)con01++;
                    
                else con00++;
            }
        }
        return min(con00+con11, con01+con10);
    }
};