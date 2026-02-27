#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    struct segment{
        int tam;
        vector<int> st[2];
        queue<pair<pair<int,int>,pair<int,bool>>> temp;
        void update(int node,int l,int r,int i,int j,int val,bool par){
            if(st[par][node]!=-1)return;
            if(r<i || j<l)return;
            if(i<=l && r<=j){
                st[par][node]=val;
                temp.push({{l,r},{val,par}});
                return;
            }
            int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
            update(hiji,l,mid,i,j,val,par);
            update(hijd,mid+1,r,i,j,val,par);
        }
        queue<pair<pair<int,int>,pair<int,bool>>> u(int i,int j,int val,bool par){
            while(!temp.empty())temp.pop();
            update(0,0,tam,i,j,val,par);
            return temp;
        }
        segment(int n){
            st[0].assign(4*n+10,-1);
            st[1].assign(4*n+10,-1);
            tam=n;
        }
    };
    int minOperations(string s,int k){
        int can0=count(s.begin(),s.end(),'0'),res=0,n=s.size();
        queue<pair<pair<int,int>,pair<int,bool>>> bfs;
        segment clave(n);
        queue<pair<pair<int,int>,pair<int,bool>>> nue=clave.u(can0,can0,0,can0&1);
        while(!nue.empty()){
            bfs.push(nue.front());
            nue.pop();
        }
        while(!bfs.empty()){
            pair<int,int> top=bfs.front().first;
            int dis=bfs.front().second.first;
            bool pari=bfs.front().second.second;
            bfs.pop();
            if(top.first==0)return dis;
            for(int j=top.first+((top.first&1) != pari);j<=top.second;j+=2){
                queue<pair<pair<int,int>,pair<int,bool>>> nue=clave.u(j+k-2*min(j,k),j+k-2*max(k-n+j,0),dis+1,(j+k)&1);
                while(!nue.empty()){
                    bfs.push(nue.front());
                    nue.pop();
                }
            }
        }
        return -1;
    }
};