#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string smallestPalindrome(string s){
        int mid=-1;
        vector<int> con(26);
        string res;
        for(auto u:s)con[u-'a']++;
        for(int i=0;i<26;i++){
            res.append(string(con[i]/2,char(i+'a')));
            if(con[i]&1)mid=i;
        }
        string cop=res;
        reverse(cop.begin(),cop.end());
        if(mid!=-1)res.push_back(char(mid)+'a');
        return res+cop;
    }
};