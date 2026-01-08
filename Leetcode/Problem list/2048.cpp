#include <bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
class Solution {
public:
    int nextBeautifulNumber(int n){
        for(int i=n+1;1;i++){
            vector<int> con(10);
            int a=i;
            while(a){
                con[a%10]++;
                a/=10;
            }
            bool xd=true;
            for(int j=0;j<10;j++){
                if(con[j]!=0){
                    if(j!=con[j]){
                        xd=false;
                    }
                }
            }
            if(xd){
                return i;
            }
        }
    }
};