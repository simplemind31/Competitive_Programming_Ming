#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    const int MAXN=50000;
    vector<int> gcdValues(vector<int>& nums,vector<ll>& queries){
        vector<ll> con(MAXN+1);
        int q=queries.size();
        vector<int> res(q);
        for(auto u:nums)con[u]++;
        for(int i=1;i<=MAXN;i++)for(int j=2;j*i<=MAXN;j++)con[i]+=con[i*j];
        for(int i=MAXN;i>=1;i--){
            con[i]=con[i]*(con[i]-1)/2;
            for(int j=2;j*i<=MAXN;j++)con[i]-=con[i*j];
        }
        for(int i=1;i<=MAXN;i++)con[i]+=con[i-1];
        for(int i=0;i<q;i++)res[i]=lower_bound(con.begin(),con.end(),queries[i]+1)-con.begin();
        return res;
    }
};