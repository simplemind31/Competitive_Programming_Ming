#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,c,d;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    int mat[n+2][n+2];
    memset(mat,0,sizeof(mat));
    while(m--){
        cin >> a >> b >> c >> d;
        mat[a][b]++;
        mat[a][d+1]--;
        mat[c+1][b]--;
        mat[c+1][d+1]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mat[i][j]+=mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
            cout << mat[i][j] << " \n"[j==n];
        }
    }
}