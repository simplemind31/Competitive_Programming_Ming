#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    int longestBalanced(string s){
        int res=0;
        for(int i=0,n=s.size();i+res<n;i++){
            vector<int> con(26);
            for(int j=i;j<n;j++){
                con[s[j]-'a']++;
                if(res>=j-i+1)continue;
                int tem=0;
                bool xd=true;
                for(int k=0;xd && k<26;k++){
                    if(con[k]==0)continue;
                    if(tem==0)tem=con[k];
                    else if(tem!=con[k])xd=false;
                }
                if(xd)res=max(res,j-i+1);
            }
        }
        return res;
    }
};