#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string lexGreaterPermutation(string s, string target){
        int n=s.size();
        vector<int> con1(26),cop;
        for(auto u:s)con1[u-'a']++;
        cop=con1;
        int posi=-1,val=-1;
        for(int i=0;i<n;i++){
            for(int j=target[i]-'a'+1;j<='z'-'a' && posi!=i;j++){
                if(!con1[j])continue;
                posi=i;
                val=j;
            }
            if(!con1[target[i]-'a'])break;
            con1[target[i]-'a']--;
        }
        if(posi==-1)return "";
        string res="";
        con1=cop;
        // until posi-1 todo igual
        for(int i=0;i<posi;i++){
            res.push_back(target[i]);
            con1[target[i]-'a']--;
        }
        res.push_back(val+'a');
        con1[val]--;
        for(int i=0;i<26;i++){
            for(int j=0;j<con1[i];j++)res.push_back(i+'a');
        }
        return res;
    }
};