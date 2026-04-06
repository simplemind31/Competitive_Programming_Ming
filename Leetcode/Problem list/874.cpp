#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
pair<int,int> operator+(pair<int,int> a,pair<int,int> b){return make_pair(a.first+b.first,a.second+b.second);}
ll val(pair<int,int> a){return 1ll*a.first*100000+a.second;}
class Solution {
public:
    pair<int,int> directions[4]={{0,1},{1,0},{0,-1},{-1,0}};
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles){
        int n=obstacles.size();
        unordered_map<ll,bool> NO(n);
        for(auto u:obstacles)NO[1ll*u[0]*100000+u[1]]=true;
        pair<int,int> pos={0,0};
        int direc=0,res=0;
        for(auto u:commands){
            if(u==-1)direc=(direc+1)%4;
            else if(u==-2)direc=(direc+3)%4;
            else{
                while(u-- && !NO[val(pos+directions[direc])]){
                    pos=pos+directions[direc];
                    res=max(res,pos.first*pos.first+pos.second*pos.second);
                }
            }
        }
        return res;
    }
};