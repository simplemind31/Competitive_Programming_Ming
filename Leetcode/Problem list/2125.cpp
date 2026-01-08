#include <bits/stdc++.h>
using namespace std;
int suma;
short n,m,last,now;
class Solution {
public:
    int numberOfBeams(vector<string>&bank){
        suma=last=now=0;
        n=bank.size();
        string x(m=bank[0].size(),'0');
        for(short i=0;i<n;i++){
            if(bank[i]==x)continue;
            for(char u:bank[i])if(u-48)now++;
            suma+=(int)(last*now);
            last=now;
            now=0;
        }
        return suma;
    }
};