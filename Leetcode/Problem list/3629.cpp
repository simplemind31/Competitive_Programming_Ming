#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000000;
int m;
vector<int> primes,criba;
class Solution{
public:
    int minJumps(vector<int>& nums){
        if(primes.empty()){
            criba.assign(MAXN+1,0);
            criba[0]=0;
            criba[1]=1;
            for(int i=2;i<=MAXN;i++){
                if(!criba[i]){
                    primes.push_back(i);
                    criba[i]=i;
                }
                for(int j=0;j<primes.size() && i*primes[j]<=MAXN;j++){
                    criba[i*primes[j]]=primes[j];
                    if(i%primes[j]==0)break;
                }
            }
            m=primes.size();
        }
        unordered_map<int,vector<int>> conta;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(criba[nums[i]]==nums[i])conta[nums[i]].push_back(i);
        }
        vector<int> dist(n,1e9);
        dist[n-1]=0;
        queue<int> bfs;
        bfs.push(n-1);
        while(!bfs.empty()){
            int top=bfs.front();
            bfs.pop();
            if(top+1<n && dist[top+1]==1e9){
                dist[top+1]=dist[top]+1;
                bfs.push(top+1);
            }
            if(top-1>=0 && dist[top-1]==1e9){
                dist[top-1]=dist[top]+1;
                bfs.push(top-1);
            }
            int x=nums[top];
            while(x>1){
                int p=criba[x];
                for(auto u:conta[p]){
                    if(dist[u]==1e9){
                        dist[u]=dist[top]+1;
                        bfs.push(u);
                    }
                }
                conta[p].clear();
                while(x%p==0){
                    x/=p;
                }
            }
        }
        return dist[0];
    }
};