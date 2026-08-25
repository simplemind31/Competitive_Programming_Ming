#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool sumGame(string num){
        bool xd=false;
        int n=num.size(),sum=0,can=0;
        for(int i=0;i<n;i++){
            if(num[i]=='?')can+=((i<n/2)?1:-1),xd=true;
            else sum+=(i<n/2?num[i]-'0':-(num[i]-'0'));
        }
        if(!xd)return sum;
        // alice can choose the last one, try to make iz!=de
        return (can%2!=0 || sum+can/2*9);
    }
};