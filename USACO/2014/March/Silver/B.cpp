#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,k,maxi,mat[800][800];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("lazy.in","r",stdin);
    freopen("lazy.out","w",stdout);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mat[i+j+1][n-i+j];
        }
    }
    //psum centro i,j -> i-k,j-k  i+k,j+k
    for(int i=1;i<2*n;i++){
        for(int j=1;j<2*n;j++){
            mat[i][j]+=mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
        }
    }
    for(int i=1;i<2*n;i++){
        for(int j=1;j<2*n;j++){
            int sum=0;
            sum+=mat[i][j];
            sum-=(j-2*k-1<0)?0:mat[i][j-2*k-1];
            sum-=(i-2*k-1<0)?0:mat[i-2*k-1][j];
            sum+=(j-2*k-1<0 || i-2*k-1<0)?0:mat[i-2*k-1][j-2*k-1];
            maxi=max(maxi,sum);
        }
    }
    cout << maxi;
}