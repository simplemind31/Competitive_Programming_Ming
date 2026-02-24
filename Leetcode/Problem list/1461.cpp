#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasAllCodes(string s, int k){
        int num=0,n=s.size(),x=0,temp=k-1+(1<<k);
        if(temp>n)return false;
        bool con[1<<k];
        memset(con,0,sizeof(con));
        for(int i=0;i<k;i++){
            num<<=1;
            num+=s[i]-'0';
        }
        con[num]=true;
        for(int i=k;i<n;i++){
            num-=(s[i-k]-'0')<<(k-1);
            num<<=1;
            num+=s[i]-'0';
            if(con[num])x++;
            if(temp>n-x)return false;
            con[num]=true;
        }
        return true;
    }
};