#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<vector<int>> matrix;
matrix I(6,vector<int>(6));
matrix operator*(matrix a,matrix b){
    int n=a.size(),m=b[0].size(),p=b.size();
    matrix c(6,vector<int>(6));
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
ll n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    // f(n)=f(n-1)+f(n-2)+...+f(n-5)
    matrix base(6,vector<int>(1)),trans(6,vector<int>(6));
    for(int i=5;i>=0;i--)base[i][0]=1<<(5-i);
    for(int i=0;i<6;i++)trans[0][i]=I[i][i]=1;
    for(int i=1;i<6;i++)trans[i][i-1]=1;
    n--;
    if(n<=5)cout << base[5-n][0];
    else cout << (exp(trans,n-5)*base)[0][0];
}