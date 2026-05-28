#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,a,b,c;
struct DSU{
    vector<int> tam,pad;
    vector<bool> parity;
    pair<int,int> find(int x){
        // (padre, parity)
        if(x==pad[x])return {x,0};
        pair<int,int> ne=find(pad[x]);
        pad[x]=ne.first;
        parity[x]=!ne.second;
        return {pad[x],parity[x]};
    }
    bool unite(int x,int y){
        pair<int,int> rex=find(x),rey=find(y);
        if(tam[rex.first]<tam[rey.first]){
            swap(rex,rey);
            swap(x,y);
        }
    }
    void add(){
        tam.push_back(1);
        pad.push_back(tam.size());
        parity.push_back(0);
    }
    DSU(int x){
        tam.resize(x);
        pad=tam;
        parity.resize(x);
        for(int i=0;i<x;i++)tam[pad[i]=i]=1;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //bipartity check
    cin >> n;
    DSU clav(n);
    while(1){
        cin >> a >> b >> c;
        if(a+b+c==0)return 0;
        if(a==1){
            // make same parity
        }else if(a==2){
            // unite
            clav.unite(b,c)
        }else if(a==3){
            // son friends?
        }else{
            // son enemies?
        }
    }
}