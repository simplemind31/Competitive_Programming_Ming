#include <bits/stdc++.h>
using namespace std;
int n;
string res;
class Solution {
public:
    string convert(string s, int numRows){
        if(numRows==1)return s;
        vector<int> princ;
        for(int i=0;i<numRows;i++){
            s.push_back(' ');
        }
        n=s.size();
        for(int i=0;i<n;i+=2*(numRows-1))princ.push_back(i);
        res="";
        for(auto u:princ){
            if(s[u]==' ')continue;
            res.push_back(s[u]);
        }
        for(int can=1;can<=numRows-2;can++){
            for(auto u:princ){
                if(u-can>=0){
                    if(s[u-can]==' ')continue;
                    res.push_back(s[u-can]);
                }
                if(u+can<n){
                    if(s[u+can]==' ')continue;
                    res.push_back(s[u+can]);
                }
            }
        }
        for(auto u:princ){
            if(u+numRows-1<n){
                if(s[u+numRows-1]==' ')continue;
                res.push_back(s[u+numRows-1]);
            }
        }
        return res;
    }
};