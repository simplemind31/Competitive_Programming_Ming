#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
vector<vector<ll>> transimatrix,inicial;
ll n,m;
vector<vector<ll>> operator*(vector<vector<ll>>& a,vector<vector<ll>>& b){
    int x=a.size(),y=a[0].size(),z=b[0].size();
    vector<vector<ll>> c(x,vector<ll>(z));
    for(int i=0;i<x;i++){
        for(int j=0;j<z;j++){
            for(int k=0;k<y;k++){
                c[i][j]=(c[i][j]+a[i][k]*b[k][j])%MOD;
            }
        }
    }
    return c;
}
vector<vector<ll>> operator^(vector<vector<ll>> b,ll e){
    int x=b.size();
    vector<vector<ll>> p(x,vector<ll>(x));
    for(int i=0;i<x;i++)p[i][i]=1;
    //identidad;
    while(e){
        if(e&1)p=p*b;
        b=b*b;
        e>>=1;
    }
    return p;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    if(n<m){
        cout << 1;
        return 0;
    }
    transimatrix.assign(m,vector<ll>(m));
    transimatrix[0][0]=transimatrix[0][m-1]=1;
    for(int i=1;i<m;i++)transimatrix[i][i-1]=1;
    inicial.assign(m,vector<ll>(1,1));
    // cada split es m, entonces no puedo splitear para n<m
    //dp0,dp1,dp2,...dpm-1
    // tengo que hacer n-m+1 transiciones
    vector<vector<ll>> a=transimatrix^(n-m+1);
    cout << (a*inicial)[0][0];
}