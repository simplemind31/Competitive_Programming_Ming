#include <bits/stdc++.h>
#define LsOne(x) x&(-x)
using namespace std;
typedef long long ll;
int n,a,b,q,tiempo,t,x,y;
pair<int,int> entrasal[300001];
vector<int> graph[300001];
vector<long double> ori;
struct BIT{
    vector<long double> fenwick;
    void update(int pos,long double val){
        while(pos<=n){
            fenwick[pos]+=val;
            pos+=LsOne(pos);
        }
    }
    long double sum(int pos){
        long double suma=0;
        while(pos>0){
            suma+=fenwick[pos];
            pos-=LsOne(pos);
        }
        return suma;
    }
    long double rango(pair<int,int> par){
        return sum(par.second)-sum(par.first-1);
    }
    BIT(int a){
        fenwick.resize(n+1);
    }
};
void dfs(int node,int ante){
    entrasal[node].first=++tiempo;
    for(auto u:graph[node])if(u!=ante)dfs(u,node);
    entrasal[node].second=tiempo;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,-1);
    ori.resize(n+1);
    BIT sol(0);
    cin >> q;
    cout << fixed << setprecision(6);
    while(q--){
        cin >> t >> x >> y;
        if(t==1){
            sol.update(entrasal[x].first,log10l(y)-ori[x]);
            ori[x]=log10l(y);
        }else{
            long double val=sol.rango(entrasal[x])-sol.rango(entrasal[y]);
            if(val>=9)cout << "1000000000\n";
            else cout << powl(10,val) << '\n';
        }
    }
}