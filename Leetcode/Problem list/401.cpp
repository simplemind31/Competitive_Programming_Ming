#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn){
        vector<string> res;
        string temp;
        for(int i=0;i<12;i++){
            if(__builtin_popcount(i)>turnedOn)continue;
            temp=to_string(i);
            temp.push_back(':');
            for(int j=0;j<60;j++){
                if(__builtin_popcount(j)+__builtin_popcount(i)==turnedOn){
                    if(j<10)res.push_back(temp+"0"+to_string(j));
                    else res.push_back(temp+to_string(j));
                }
            }
        }
        return res;
    }
};