#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHappyString(int n, int k){
        int dp[n+1];
        // fixeo
        dp[0]=0;dp[1]=1;
        for(int i=2;i<=min(10,n);i++){
            // si fixeo a, elijo entre b y c
            dp[i]=dp[i-1]*2;
        }
        for(int i=11;i<=n;i++)dp[i]=dp[i-1];
        if(3*dp[n]<k)return "";
        string st="";
        if(dp[n]>=k){
            st.push_back('a');
        }else if(2*dp[n]>=k){
            st.push_back('b');
            k-=dp[n];
        }else{
            st.push_back('c');
            k-=2*dp[n];
        }
        for(int i=n-1;i>0;i--){
            // depende de lo anterior
            if(dp[i]>=k){
                // ir al primero
                if(st.back()=='a')st.push_back('b');
                else st.push_back('a');
            }else{
                k-=dp[i];
                if(st.back()=='c')st.push_back('b');
                else st.push_back('c');
            }
        }
        return st;
    }
};