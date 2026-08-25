#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;
matrix I;
matrix operator*(matrix a,matrix b){
    int n=a.size(),m=b[0].size(),p=b.size();
    matrix c(n,vector<ll>(m,2e18));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<p;k++){
                c[i][j]=min(a[i][k]+b[k][j],c[i][j]);
            }
        }
    }
    return c;
}
matrix exp(matrix b,ll e){
    matrix p=I;
    for(;e;e>>=1,b=b*b)if(e&1)p=b*p;
    return p;
}
ll n,m,k,a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    matrix base(n,vector<ll>(n,2e18));
    I=base;
    while(m--){
        cin >> a >> b >> c;
        b--;a--;
        base[a][b]=min(base[a][b],c);
    }
    for(int i=0;i<n;i++)I[i][i]=0;
    ll res=exp(base,k)[0][n-1];
    if(res==2e18)res=-1;
    cout << res;
}