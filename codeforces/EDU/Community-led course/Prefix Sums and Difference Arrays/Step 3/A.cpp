#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,a,q,b,c,d;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    ll mat[n+1][m+1];
    for(int i=0;i<=n;i++)mat[i][0]=0;
    for(int j=0;j<=m;j++)mat[0][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a;
            mat[i][j]=a+mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
        }
    }
    cin >> q;
    while(q--){
        cin >> a >> b >> c >> d;
        cout << mat[c][d]-mat[a-1][d]-mat[c][b-1]+mat[a-1][b-1] << '\n';
    }
}