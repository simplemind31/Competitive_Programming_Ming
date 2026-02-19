#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int mat[n][n];
    cout << (mat[0][0]=1) << '\n';
    for(int i=1;i<n;i++){
        cout << (mat[i][0]=1) << ' ';
        for(int j=1;j<i;j++){
            cout << (mat[i][j]=mat[i-1][j]+mat[i-1][j-1]) << ' ';
        }
        cout << (mat[i][i]=1) << '\n';
    }
}