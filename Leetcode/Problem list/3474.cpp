#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
class Solution {
public:
    string generateString(string str1, string str2){
        int n=str1.size(),m=str2.size();
        string word(n+m-1,' ');
        vector<bool> fixed(n+m-1);
        for(int i=0;i<n;i++){
            if(str1[i]=='T'){
                for(int j=0;j<m;j++){
                    if(word[i+j]!=' ' && word[i+j]!=str2[j])return "";
                    word[i+j]=str2[j];
                    fixed[i+j]=true;
                }
            }
        }
        for(int i=0;i<n+m-1;i++){
            if(!fixed[i])word[i]='a';
        }
        for(int i=0;i<n;i++){
            if(str1[i]=='F'){
                bool xd=true;
                for(int j=0;j<m && xd;j++){
                    if(word[i+j]!=str2[j]){
                        xd=false;
                    }
                }
                for(int j=m-1;j>=0 && xd;j--){
                    if(fixed[i+j])continue;
                    if(word[i+j]=='z')continue;
                    word[i+j]++;
                    xd=false;
                }
                if(xd)return "";
            }
        }
        return word;
    }
};