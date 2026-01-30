#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    ll minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost){
        vector<int> ori(original.size()),cha=ori;
        map<string,int> clave;
        unordered_set<int> lens;
        int now=1,antenow;
        for(auto u:original)if(clave[u]==0)clave[u]=now++;
        for(auto u:changed)if(clave[u]==0)clave[u]=now++;
        for(int i=0,n=original.size();i<n;i++){
            lens.insert(original[i].size());
            ori[i]=clave[original[i]];
            cha[i]=clave[changed[i]];
        }
        ll dist[now][now];
        for(int i=0;i<now;i++){
            for(int j=0;j<now;j++){
                dist[i][j]=1e18;
            }
            dist[i][i]=0;
        }
        for(int i=0;i<ori.size();i++){
            dist[ori[i]][cha[i]]=min(dist[ori[i]][cha[i]],(ll)cost[i]);
        }
        for(int i=0;i<now;i++){
            for(int j=0;j<now;j++){
                for(int k=0;k<now;k++){
                    dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
                }
            }
        }
        antenow=now;
        int n=target.size();
        ll dp[n+1];
        for(int i=0;i<=n;i++)dp[i]=1e18;
        dp[0]=0;
        for(int i=0;i<n;i++){
            if(dp[i]==1e18)continue;
            if(source[i]==target[i])dp[i+1]=min(dp[i],dp[i+1]);
            for(int L:lens){
                if(i+L>n)continue;
                string s=source.substr(i,L);
                string t=target.substr(i,L);
                if(clave.count(s) && clave.count(t)){
                    ll d=dist[clave[s]][clave[t]];
                    if(d!=1e18)dp[i+L]=min(dp[i+L],dp[i]+d);
                }
            }
        }
        if(dp[n]==1e18)return -1;
        return dp[n];
    }
};