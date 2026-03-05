#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,n,m,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m >> a >> b;
        if(n*a!=m*b){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        vector<vector<bool>> mat(n,vector<bool>(m));
        int now=0,can=0;
        for(int i=0;i<m;i++){
            while(can!=b){
                mat[now][i]=1;
                can++;
                now=(now+1)%n;
            }
            can=0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << mat[i][j];
            }
            cout << '\n';
        }
    }
}