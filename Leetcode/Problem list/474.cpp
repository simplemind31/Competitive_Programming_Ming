#include <bits/stdc++.h>
using namespace std;
int tam,maxi,one,zero;
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n){
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        vector<pair<int,int>> pares(tam=strs.size());
        for(int i=maxi=0;i<tam;i++){
            zero=strs[i].size();
            for(int j=one=0;j<zero;j++)if(strs[i][j]-48)one++;
            pares[i]={zero-one,one};
        }
        for(int k=0;k<tam;k++){
            for(int i=m;i>=0;i--){
                for(int j=n;j>=0;j--){
                    if(i-pares[k].first>=0 && j-pares[k].second>=0)maxi=max(maxi,dp[i][j]=max(dp[i][j],dp[i-pares[k].first][j-pares[k].second]+1));
                }
            }
        }
        return maxi;
    }
};