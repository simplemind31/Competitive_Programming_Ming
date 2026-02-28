#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
class Solution {
public:
    int concatenatedBinary(int n){
        int ne=1;
        ll res=0;
        for(int i=1;i<=n;i++){
            if(i==(1<<ne))ne++;
            res=((res<<ne)|i)%MOD;
        }
        return res;
    }
};