#include <bits/stdc++.h>
using namespace std;
int tot,can,n;
class Solution {
public:
    int maxOperations(string s){
        tot=can=0;
        n=s.size();
        for(int i=0;i<n-1;i++){
            if(s[i]-48){
                can++;
                if(s[i+1]-48==0)tot+=can;
            }
        }
        return tot;
    }
};