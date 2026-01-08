#include <bits/stdc++.h>
using namespace std;
int n;
class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive){
        n=code.size();
        vector<string> res[4];
        for(int i=0;i<n;i++){
            if(isActive[i] && !code[i].empty()){
                bool xd=true;
                for(auto u:code[i]){
                    if(!(('a'<=u && u<='z')||('A'<=u && u<='Z')||('0'<=u && u<='9')||(u=='_'))){
                        xd=false;
                        break;
                    }
                }
                if(xd){
                    if(businessLine[i]=="electronics"){
                        res[0].push_back(code[i]);
                    }else if(businessLine[i]=="grocery"){
                        res[1].push_back(code[i]);
                    }else if(businessLine[i]=="pharmacy"){
                        res[2].push_back(code[i]);
                    }else if(businessLine[i]=="restaurant"){
                        res[3].push_back(code[i]);
                    }
                }
            }
        }
        vector<string> supres;
        for(int i=0;i<4;i++){
            sort(res[i].begin(),res[i].end());
            for(auto u:res[i]){
                supres.push_back(u);
            }
        }
        return supres;
    }
};