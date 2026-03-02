#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,x,q,t,a,b;
struct DSU{
    vector<int> dsu,tam,maxi;
    int find(int a){return (a==dsu[a])?a:dsu[a]=find(dsu[a]);}
    bool unite(int a,int b){
        if((a=find(a))==(b=find(b)))return false;
        if(tam[a]<tam[b])swap(a,b);
        tam[dsu[b]=a]+=tam[b];
        maxi[a]=max(maxi[a],maxi[b]);
        return true;
    }
    DSU(int n){
        dsu.resize(n+1);
        tam.resize(n+1);
        maxi.resize(n+1);
        for(int i=0;i<=n;i++)tam[maxi[i]=dsu[i]=i]=1;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    DSU res1(n);
    DSU res2(n);
    while(q--){
        cin >> t >> a >> b;
        a--;b--;
        if(t==1){
            res1.unite(a,b);
            //if(b==a+1)res2.unite(a,b);
        }else if(t==3){
            cout << ((res1.find(a)==res1.find(b))?"YES":"NO") << '\n';
        }else{
            while(res2.maxi[res2.find(a)]+1<=b){
                res1.unite(a,res2.maxi[res2.find(a)]+1);
                res2.unite(a,res2.maxi[res2.find(a)]+1);
            }
        }
    }
}