#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countBinarySubstrings(string s){
        int res=0,con=1;
        vector<int> temp;
        for(int i=1,n=s.size();i<n;i++){
            if(s[i]==s[i-1])con++;
            else{
                temp.push_back(con);
                con=1;
            }
        }
        temp.push_back(con);
        for(int i=1;i<temp.size();i++)res+=min(temp[i],temp[i-1]);
        return res;
    }
};