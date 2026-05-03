#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rotatedDigits(int n){
        int can=0;
        for(int i=1;i<=n;i++){
            int a=i;
            bool xd=true,lol=false;
            while(a && xd){
                int d=a%10;
                switch(d){
                    case 3:
                    case 4:
                    case 7:
                        xd=false;
                        break;
                    case 2:
                    case 5:
                    case 6:
                    case 9:
                        lol=true;
                        break;
                }
                a/=10;
            }
            can+=xd&&lol;
        }
        return can;
    }
};