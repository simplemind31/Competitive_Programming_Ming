#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countTriples(int n){
        int con=0;
        // x2-y2,2xy,x2+y2
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int c=sqrt(i*i+j*j);
                if(c>n)break;
                if(c*c==i*i+j*j)con++;
            }
        }
        return con;
    }
};