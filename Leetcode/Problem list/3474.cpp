#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
class Solution {
public:
    string generateString(string str1, string str2){
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        const int B=uniform_int_distribution<int> (1,MOD-1)(rng);
        int n=str1.size(),m=str2.size();
        int valstr2=0;
        for(int i=0;i<m;i++){
            valstr2=(1ll*valstr2*B+str2[i])%MOD;
        }
        string word(n+m-1,' ');
        for(int i=0;i<n;i++){
            if(str1[i]=='T'){
                for(int j=0;j<m;j++){
                    if(word[i+j]!=' ' && word[i+j]!=str2[j])return "";
                    word[i+j]=str2[j];
                }
            }
        }
        // hash?
        for(int i=0;i<n;i++){
            // todo F deben cumplir
            if(str1[i]=='F'){
                int valnow=0;
                for(int j=0;j<m;j++){
                    valnow=(1ll*valnow*B+word[i+j])%MOD;
                }
                if(valnow==valstr2)return "";
            }
        }
        return word;
    }
};