#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 998244353
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
int pad[100000],raiz,dsu[100000],tam[100000];
ll a,b,c,n,m,res;
vector<pair<int,int>> ahora;
vector<vector<int>> graph;
int find(int x){return(x==dsu[x])?x:dsu[x]=find(dsu[x]);}
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(tam[y]>tam[x])swap(x,y);
    dsu[y]=x;
    tam[x]+=tam[y];
}
void dfs(int now,int ante){
    for(auto u:graph[now]){
        if(u==ante)continue;
        pad[u]=now;
        dfs(u,now);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        dsu[i]=i;
        tam[i]=1;
    }
    graph.clear();
    graph.resize(n);
    raiz=sqrt(m);
    for(int i=0;i<n;i++)pad[i]=i;
    for(int i=0;i<m;i++){
        if(i%raiz==0){
            for(auto u:ahora){
                unite(u.first,u.second);
                graph[u.first].push_back(u.second);
                graph[u.second].push_back(u.first);
            }
            ahora.clear();
            for(int i=0;i<n;i++)pad[i]=i;
            for(int i=0;i<n;i++)if(pad[i]==i)dfs(i,-1);
        }
        cin >> a >> b >> c;
        int A=(((a*(1+res))%MOD)%2),B=(((b*(1+res))%MOD)%n),C=(((c*(1+res))%MOD)%n);
        if(B>C)swap(B,C);
        if(A){
            res=0;
            if(find(B)==find(C)){
                if(pad[B]==C || pad[C]==B)res=0;
                else if(pad[B]==pad[C])res=pad[B]+1;
                else if(pad[pad[B]]==C)res=pad[B]+1;
                else if(pad[pad[C]]==B)res=pad[C]+1;
                else res=0;
            }else{
                bool xd=false;
                unordered_map<int,bool> exis;
                for(auto u:ahora){
                    if(u.first==B || u.second==B)exis[u.first+u.second-B]=true;
                    if(u.first==B && u.second==C){
                        xd=true;
                        res=0;
                        break;
                    }
                    if(u.first!=B && u.second!=B)continue;
                    int nue=u.first+u.second-B;
                    if(pad[nue]==C || pad[C]==nue){
                        res=nue+1;
                        xd=true;
                        break;
                    }
                }
                if(!xd){
                    for(auto u:ahora){
                        if(u.first!=C && u.second!=C)continue;
                        int nue=u.first+u.second-C;
                        if(pad[nue]==B || pad[B]==nue){
                            res=nue+1;
                            xd=true;
                            break;
                        }
                    }
                }
                if(!xd){
                    for(auto u:ahora){
                        if(u.first!=C && u.second!=C)continue;
                        int nue=u.first+u.second-C;
                        if(exis[nue]){
                            xd=true;
                            res=nue+1;
                            break;
                        }
                    }
                }
            }
            cout << res << '\n';
        }else ahora.push_back({B,C});
    }
}