#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,a,b,c;
struct DSU{
    vector<int> tam,pad;// dist al root
    vector<bool> parity;
    int find(int x){
        if(x==pad[x])return x;
        int ne=pad[x];
        pad[x]=find(pad[x]);
        parity[x]=parity[x]^parity[ne];
        return pad[x];
    }
    bool unite(int x,int y){
        int rex=find(x),rey=find(y);
        if(rex==rey)return false;
        if(tam[rex]<tam[rey]){
            swap(rex,rey);
            swap(x,y);
        }
        tam[pad[rey]=rex]+=tam[rey];
        parity[rey]=parity[x]^1^parity[y];
        return true;
    }
    void add(){
        tam.push_back(1);
        pad.push_back(pad.size());
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
            if(clav.find(b)==clav.find(c) && clav.parity[b]!=clav.parity[c])cout << "-1\n";
            else{
                clav.add();
                clav.unite(b,clav.tam.size()-1);
                clav.unite(c,clav.tam.size()-1);
            }
            // make same parity
        }else if(a==2){
            // unite
            if(!clav.unite(b,c) && clav.parity[b]==clav.parity[c])cout << "-1\n";
        }else if(clav.find(b)!=clav.find(c)){
            cout << "0\n";
        }else{
            cout << ((a==4)^(clav.parity[b]==clav.parity[c])) << '\n';
        }
    }
}