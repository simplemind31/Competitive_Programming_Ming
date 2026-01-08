#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,res,nece,ag;
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& polls){
        sort(polls.begin(),polls.end());
        unordered_map<int,ll> con,mid;
        unordered_map<ll,bool> pertenece_slope;
        map<ll,vector<ll>> conjunto;
        for(int i=(n=polls.size())-1;i>=0;i--){
            polls[i][0]+=1000;
            polls[i][1]+=1000;
        }
        for(int i=res=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ll y=polls[j][1]-polls[i][1];
                ll x=polls[j][0]-polls[i][0];
                if(x==0)y=1;
                else if(y==0)x=1;
                else{
                    nece=__gcd(y,x);
                    y/=nece;
                    x/=nece;
                }
                if(y<0){
                    con[1e8-y*1e4+x]++;
                    nece=(1e12)-y*(1e8)+x*(1e4)+i;
                }else{
                    con[y*1e4+x]++;
                    nece=(y*1e8)+x*(1e4)+i;
                }
                if(!pertenece_slope[nece]){
                    pertenece_slope[nece]=true;
                    conjunto[nece].push_back(i);
                }
                ag=nece-i+j;
                if(!pertenece_slope[ag]){
                    pertenece_slope[ag]=true;
                    conjunto[nece].push_back(j);
                }
            }
        }
        for(auto u:con)res+=u.second*(u.second-1)/2;
        for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)mid[(polls[i][0]+polls[j][0])*1e4+polls[i][1]+polls[j][1]]++;
        for(auto u:mid)res-=u.second*(u.second-1)/2;
        for(auto u:conjunto){
            vector<ll> noseque=u.second;
            ll tam=noseque.size();
            res-=(tam*(tam-1)*(tam-2)*(tam-3)/8+tam*(tam-1)*(tam-2)/2);
            unordered_map<ll,ll> ashh;
            for(ll i=0;i<tam;i++)for(int j=i+1;j<tam;j++)ashh[(polls[noseque[i]][0]+polls[noseque[j]][0])*1e4+polls[noseque[i]][1]+polls[noseque[j]][1]]++;
            for(auto v:ashh)res+=v.second*(v.second-1)/2;
        }
        return res;
    }
};