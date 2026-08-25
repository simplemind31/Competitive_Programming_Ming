#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> con(26);
        int l=0,maxi=0,n=s.size();
        for(int r=0;r<n;r++){
            con[s[r]-'a']++;
            while(con[s[r]-'a']==3)con[s[l++]-'a']--;
            maxi=max(maxi,r-l+1);
        }
        return maxi;
    }
};