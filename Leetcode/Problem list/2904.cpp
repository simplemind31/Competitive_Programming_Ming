#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k){
        int n=s.size();
        string res="";
        for(int i=0;i<n;i++){
            int con=0;
            string now="";
            for(int j=i;j<n && con<k;j++){
                con+=s[j]=='1';
                now.push_back(s[j]);
            }
            if(con==k && (res.empty() || now.size()<res.size() || (now.size()==res.size() && now<res)))res=now;
        }
        return res;
    }
};