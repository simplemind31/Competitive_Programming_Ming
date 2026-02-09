#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeletions(string s){
        int n=s.size(),res=1e9,b=0;
        vector<int> con(n);
        con[n-1]=(s[n-1]=='a');
        for(int i=n-2;i>=0;i--)con[i]=con[i+1]+(s[i]=='a');
        for(int i=0;i<n;i++){
            res=min(res,b+con[i]);
            b+=(s[i]=='b');
        }
        res=min(res,b);
        return res;
    }
};