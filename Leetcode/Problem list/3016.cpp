#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumPushes(string word){
        int con[26],res=0;
        memset(con,0,sizeof(con));
        for(auto &u:word)con[u-'a']++;
        sort(con,con+26);
        for(short i=25;i>=0 && con[i];i--)res+=((25-i)/8+1)*con[i];
        return res;
    }
};