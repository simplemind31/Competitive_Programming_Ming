#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<vector<int>> matrix;
matrix I;
matrix operator*(matrix a,matrix b){
    int n=a.size(),m=b[0].size(),p=b.size();
    matrix c(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<p;k++){
                c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%MOD;
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
ll n,m,k,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    matrix base(n,vector<int>(n));
    I=base;
    while(m--){
        cin >> a >> b;
        base[--a][--b]++;
    }
    for(int i=0;i<n;i++)I[i][i]=1;
    cout << exp(base,k)[0][n-1];
}