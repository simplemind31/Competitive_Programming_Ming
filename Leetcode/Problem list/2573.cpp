#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string findTheString(vector<vector<int>>& lcp){
        int n=lcp.size(),now=0;
        string st(n,' ');
        for(int i=0;i<n;i++){
            bool xd=false;
            for(int j=0;j<i && !xd;j++){
                if(lcp[j][i]){
                    st[i]=st[j];
                    xd=true;
                }
            }
            if(!xd){
                if(now+'a'>'z')return "";
                st[i]=now+'a';
                now++;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int val=0;
                if(st[i]==st[j])val=1+((i+1<n && j+1<n)?lcp[i+1][j+1]:0);
                if(val!=lcp[i][j])return "";
            }
        }
        return st;
    }
};