#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char t;
int n,m,a,b,c,d;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    int psum[n+1][n+1];
    memset(psum,0,sizeof(psum));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> t;
            psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+(t=='*');
        }
    }
    while(m--){
        cin >> a >> b >> c >> d;
        cout << psum[c][d]-psum[a-1][d]-psum[c][b-1]+psum[a-1][b-1] << '\n';
    }
}