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
}