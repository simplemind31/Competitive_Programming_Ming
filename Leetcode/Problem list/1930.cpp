#include <bits/stdc++.h>
using namespace std;
int n,con;
class Solution {
public:
    int countPalindromicSubsequence(string s){
        n=s.size();
        con=0;
        int last[n+1]['z'-'a'+1];
        for(int i=0;i<'z'-'a'+1;i++){
            last[n][i]=n+1;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<'z'-'a'+1;j++){
                last[i][j]=last[i+1][j];
            }
            last[i][s[i]-'a']=i+1;
        }
        vector<string> posi;
        for(int i=0;i<'z'-'a'+1;i++){
            for(int j=0;j<'z'-'a'+1;j++){
                string temp="";
                temp.push_back(i+'a');
                temp.push_back(j+'a');
                temp.push_back(i+'a');
                posi.push_back(temp);
            }
        }
        for(auto u:posi){
            int now=0;
            bool xd=true;
            for(int j=0;j<3;j++){
                if(last[now][u[j]-'a']>n){
                    xd=false;
                    break;
                }
                now=last[now][u[j]-'a'];
            }
            if(xd)con++;
        }
        return con;
    }
};