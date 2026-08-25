#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int smallestNumber(int n,int t){
        for(int i=n;1;i++){
            int a=i,p=1;
            while(a){
                p*=a%10;
                a/=10;
            }
            if(p%t==0)return i;
        }
    }
};