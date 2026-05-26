#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSpecialChars(string word){
        short n=word.size(),res=0;
        vector<short> con1(26),con2(26);
        for(short i=0;i<n;i++){
            if(word[i]<='Z')con1[word[i]-'A']++;
            else con2[word[i]-'a']++;
        }
        for(short i=0;i<26;i++)res+=con1[i]&&con2[i];
        return res;
    }
};