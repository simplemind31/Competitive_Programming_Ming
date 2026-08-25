#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
const int MAXN=2000000;
typedef vector<vector<int>> matrix;
const matrix I={{1,0},{0,1}};
matrix operator*(matrix a,matrix b){
    int x=a.size(),y=b[0].size(),k=a[0].size();
    matrix c(x,vector<int>(y));
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(int l=0;l<k;l++){
                c[i][j]=(c[i][j]+1ll*a[i][l]*b[l][j])%MOD;
            }
        }
    }
    return c;
}
matrix exp(matrix b,ll e){
    matrix p=I;
    for(;e;e>>=1,b=b*b)if(e&1)p=p*b;
    return p;
}
ll n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    if(n==0){
        cout << 0;
        return 0;
    }
    matrix base={{1},{0}},trans={{1,1},{1,0}};
    cout << (exp(trans,n-1)*base)[0][0];
}