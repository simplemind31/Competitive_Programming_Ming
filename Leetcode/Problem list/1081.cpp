#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    string smallestSubsequence(string s){
        int n=s.size(),need=0;
        string res="";
        vector<vector<int>> last(n+1,vector<int>(26,n+1));
        for(int i=n-1;i>=0;i--){
            last[i]=last[i+1];
            last[i][s[i]-'a']=i+1;
            need|=1<<(s[i]-'a');
        }
        int ulti=0;
        while(need){
            for(int i=0;i<26;i++){
                if(!(need&(1<<i)))continue;
                // puedo usar este?
                // existe todos las letras de need a partir de ulti+1?
                bool xd=true;
                for(int j=0;j<26 && xd;j++)xd=!((need&(1<<j)) && last[last[ulti][i]-1][j]==n+1);
                if(!xd)continue;
                res.push_back(char(i+'a'));
                need-=1<<i;
                ulti=last[ulti][i];
                break;
            }
        }
        return res;
    }
};