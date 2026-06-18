#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    ll mat[n][n];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin >> mat[i][j];
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
            }
        }
    }
    cin >> m;
    while(m--){
        cin >> a >> b >> c;
        a--;b--;
        if(mat[a][b]>c){
            mat[a][b]=c;
            mat[b][a]=c;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j]=min(mat[i][j],mat[i][a]+mat[a][b]+mat[b][j]);
                    mat[i][j]=min(mat[i][j],mat[i][b]+mat[b][a]+mat[a][j]);
                }
            }
        }
        ll suma=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                suma+=mat[i][j];
            }
        }
        cout << suma << ' ';
    }
}