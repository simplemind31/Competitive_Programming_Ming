#include <bits/stdc++.h>
using namespace std;
int i,j,n,res;
class Solution {
public:
    int lengthOfLongestSubstring(string s){
        bitset<200> existe;
        i=j=res=0;
        n=s.size();
        while(j<n){
            while(existe[s[j]])existe[s[i++]]=0;
            res=max(res,j-i+1);
            existe[s[j++]]=1;
        }
        return res;
    }
};