#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkStrings(string s1, string s2){
        int n=s1.size(),con1=0;
        vector<vector<int>> con(2,vector<int>(26));
        for(int i=0;i<n;i++){
            if(++con[i&1][s1[i]-'a']==0)con1--;
            if(con[i&1][s2[i]-'a']--==0)con1++;
        }
        return con1==0;
    }
};