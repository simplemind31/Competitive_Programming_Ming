#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500;
int n,vert100[MAXN+1][MAXN+1],vert101[MAXN+1][MAXN+1],mat[MAXN+1][MAXN+1];
ll res;
/*
1001111
1011011
1101101
1101111
0111101


000001
000011
000111
001111
011111

100000
110000
111000
111100
111110
*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> mat[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mat[i][j]>=100){
                vert100[i][j]=vert100[i-1][j]+1;
                if(mat[i][j]>=101){
                    vert101[i][j]=vert101[i-1][j]+1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int mini100=1e9,mini101=1e9;
            ll can100=0,can101=0;
            for(int k=j;k>=1;k--){
                mini100=min(mini100,vert100[i][k]);
                can100+=mini100;
                mini101=min(mini101,vert101[i][k]);
                can101+=mini101;
            }
            res+=can100-can101;
        }
    }
    cout << res;
}