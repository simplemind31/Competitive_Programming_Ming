#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500;
int n;
ll mat[MAXN+1][MAXN+1],can101[MAXN+1][MAXN+1],can100[MAXN+1][MAXN+1],res;
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
            if(mat[i][j]>=101){
                can101[i][j]+=can101[i-1][j]+can101[i][j-1]-can101[i-1][j-1]+1;
                can100[i][j]+=can100[i-1][j]+can100[i][j-1]-can100[i-1][j-1]+1;
            }else if(mat[i][j]>=100){
                can100[i][j]+=can100[i-1][j]+can100[i][j-1]-can100[i-1][j-1]+1;
            }
            cout << can100[i][j]-can101[i][j] << ' ';
            res+=can100[i][j]-can101[i][j];
        }
        cout << '\n';
    }
    cout << res;
}