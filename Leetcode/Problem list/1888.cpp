#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(string s){
        int con00=0,con01=0,con10=0,con11=0;
        for(int i=0;i<s.size();i++){
            if(i&1){
                if(s[i]-48)con11++;
                else con10++;
            }else{
                if(s[i]-48)con01++;
                    
                else con00++;
            }
        }
        return min(con00+con11,con01+con10);
    }
    int minFlips(string s){
        if(s.size()%2==0)return minOperations(s);
        int res=minOperations(s);
        int n=s.size();
        vector<int> con[2][2];
        con[0][0].resize(n);
        con[0][1]=con[1][0]=con[1][1]=con[0][0];
        con[0][s[0]-48][0]++;
        for(int i=1;i<n;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    con[j][k][i]=con[j][k][i-1];
                }
            }
            con[i&1][s[i]-48][i]++;
        }
        for(int i=0;i<n;i++){
            // rotate hast i
            // lo anterior se mantiene
            int con00=con[0][0][i];
            int con01=con[0][1][i];
            int con10=con[1][0][i];
            int con11=con[1][1][i];
            // lo posterior se hace un shift
            con10+=con[0][0][n-1]-con[0][0][i];
            con00+=con[1][0][n-1]-con[1][0][i];
            con11+=con[0][1][n-1]-con[0][1][i];
            con01+=con[1][1][n-1]-con[1][1][i];
            res=min(res,min(con00+con11,con01+con10));
        }
        return res;
    }
};