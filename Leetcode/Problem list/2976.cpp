#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    ll minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost){
        ll res=0;
        vector<vector<ll>> camb(26,vector<ll>(26,1e18));
        for(int i=0,n=original.size();i<n;i++)camb[original[i]-'a'][changed[i]-'a']=min(camb[original[i]-'a'][changed[i]-'a'],(ll)cost[i]);
        for(int i=0;i<26;i++)camb[i][i]=0;
        for(int i=0;i<26;i++)for(int j=0;j<26;j++)for(int k=0;k<26;k++)camb[j][k]=min(camb[j][k],camb[j][i]+camb[i][k]);
        for(int i=0,n=source.size();i<n;i++){
            if(camb[source[i]-'a'][target[i]-'a']==1e18)return -1;
            res+=camb[source[i]-'a'][target[i]-'a'];
        }
        return res;
    }
};