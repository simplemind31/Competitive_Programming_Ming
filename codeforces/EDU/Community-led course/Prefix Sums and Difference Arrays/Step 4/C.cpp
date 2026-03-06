#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,q,m,a,b,c,d,e;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector<vector<ll>> mat(n+2,vector<ll>(m+2));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a;
            mat[i][j]+=a;
            mat[i+1][j]-=a;
            mat[i][j+1]-=a;
            mat[i+1][j+1]+=a;
        }
    }
    cin >> q;
    while(q--){
        cin >> a >> b >> c >> d >> e;
        mat[a][b]+=e;
        mat[a][d+1]-=e;
        mat[c+1][b]-=e;
        mat[c+1][d+1]+=e;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            mat[i][j]+=mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
            cout << mat[i][j] << ' ';
        }
        cout << '\n';
    }
}