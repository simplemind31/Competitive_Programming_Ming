#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string makeLargestSpecial(string s){
        vector<string> res;
        int con=0,i=0;
        for(int j=0;j<s.size();j++){
            if(s[j]=='1')con++;
            else con--;
            if(con==0){
                res.push_back("1"+makeLargestSpecial(s.substr(i+1,j-i-1))+"0");
                i=j+1;
            }
        }
        sort(res.rbegin(),res.rend());
        string ans="";
        for(auto u:res)ans+=u;
        return ans;
    }
};