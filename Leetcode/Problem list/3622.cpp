#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkDivisibility(int n){
        int a=n,b=0,c=1;
        while(a){
            b+=a%10;
            c*=a%10;
            a/=10;
        }
        return n%(b+c)==0;
    }
};