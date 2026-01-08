#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
ll now,n,res;
class Solution {
public:
    int numSub(string s){
        now=res=0;
        n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]-48){
                now++;
            }else{
                res+=now*(now+1)/2;
                res%=MOD;
                now=0;
            }
        }
        res+=now*(now+1)/2;
        return res%MOD;
    }
};