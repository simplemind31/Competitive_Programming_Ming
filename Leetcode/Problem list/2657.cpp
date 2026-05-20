#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A,vector<int>& B){
        short n=A.size(),con=0;
        ll bit=0;
        vector<int> res(n);
        for(short i=0;i<n;i++){
            if(bit&(1ll<<A[i]))con++;
            bit^=(1ll<<A[i]);
            if(bit&(1ll<<B[i]))con++;
            bit^=(1ll<<B[i]);
            res[i]=con;
        }
        return res;
    }
};