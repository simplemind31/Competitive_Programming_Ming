#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    short maxProduct(int n){
        short n1=0,n2=0,maxi=0;
        while(n){
            if(n%10>n1){
                n2=n1;
                n1=n%10;
            }else if(n%10>n2)n2=n%10;
            maxi=max((short)(n2*n1),maxi);
            n/=10;
        }
        return maxi;
    }
};