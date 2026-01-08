#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int n,con0,res,tot,j;
class Solution {
public:
    int numberOfSubstrings(string s){
        tot=(n=(s.size()))*(n+1)/2;
        vector<int> next0(n);
        for(int i=(next0[n-1]=n)-2;i>=0;i--)next0[i]=(s[i+1]-48)?next0[i+1]:(i+1);
        for(int i=res=0;i<n;i++){
            res+=(con0=(s[i]=='0'))++;
            j=next0[i];
            while(j<n){
                if(con0*con0>=n){
                    res+=n-j;
                    break;
                }
                if(con0*con0-j+i-1+con0>0){
                    if(con0*con0+i+con0-2>=next0[j])res+=next0[j]-j;
                    else res+=con0*con0-j+i+con0-1;
                }
                j=next0[j];
                con0++;
            }
        }
        return tot-res;
    }
};