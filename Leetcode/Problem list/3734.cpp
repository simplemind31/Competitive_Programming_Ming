#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string lexPalindromicPermutation(string s, string target){
        int imp=-1,n=s.size();
        vector<int> con(26),cop;
        for(auto u:s)con[u-'a']++;
        for(int i=0;i<26;i++){
            if(con[i]&1){
                if(imp!=-1)return "";
                con[imp=i]--;
            }
            con[i]/=2;
        }
        string res(n,' ');
        if(imp!=-1)res[n/2]=imp+'a';
        cop=con;
        int last=-1,i=0,val=-1;
        for(;i<n/2;i++){
            for(int j=target[i]-'a'+1;j<='z'-'a' && last!=i;j++){
                if(con[j]){
                    last=i;
                    val=j;
                }
            }
            if(!con[target[i]-'a'])break;
            con[target[i]-'a']--;
        }// 0 1 2 3 4
        bool xd=false;
        if(i==n/2){
            // el resto puede>?
            if(n&1 && res[n/2]>target[n/2])xd=true;
            if((n&1 && res[n/2]==target[n/2]) || !(n&1))for(i=(n+1)/2;i<n && !xd && target[n-i-1]>=target[i];i++)if(target[n-i-1]>target[i])xd=true;
        }
        if(xd){
            // usar target hasta (n+1)/2
            for(int i=0;i<=n/2-1;i++)res[i]=target[i];
            for(int i=(n+1)/2;i<n;i++)res[i]=res[n-i-1];
            return res;
        }
        if(last==-1)return "";
        // usar hasta last-1
        con=cop;
        for(int i=0;i<last;i++){
            res[i]=target[i];
            con[res[i]-'a']--;
        }
        res[last]=val+'a';
        con[val]--;
        for(int i=last+1;i<n/2;i++){
            for(int j=0;j<26;j++){
                if(con[j]){
                    res[i]=j+'a';
                    con[j]--;
                    break;
                }
            }
        }
        cout << last;
        for(int i=(n+1)/2;i<n;i++)res[i]=res[n-i-1];
        return res;
    }
};