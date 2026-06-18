#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int mat[n][n],ord[n];
    ll res[n];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin >> mat[i][j];
    for(int i=0;i<n;i++){
        cin >> ord[n-i-1];
        ord[n-i-1]--;
    }
    for(int k=0;k<n;k++){
        // solo usar los ord[k]
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[ord[i]][ord[j]]=min(mat[ord[i]][ord[j]],mat[ord[i]][ord[k]]+mat[ord[k]][ord[j]]);
            }
        }
        ll suma=0;
        for(int i=0;i<=k;i++){
            for(int j=0;j<=k;j++){
                suma+=mat[ord[i]][ord[j]];
            }
        }
        res[n-k-1]=suma;
    }
    for(int i=0;i<n;i++)cout << res[i] << ' ';
}