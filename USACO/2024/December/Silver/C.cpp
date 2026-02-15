#include <bits/stdc++.h>
using namespace std;
int n,q,can,a,b;
pair<int,int> pad[1002][1002];
char mat[1002][1002],c;
bitset<1002> pertenececiclo[1002],imposi[1002];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for(int i=0;i<=1001;i++){
        for(int j=0;j<=1001;j++){
            pad[i][j]={i,j};
        }
    }
    while(q--){
        cin >> a >> b >> c;
        if(c=='L')pad[a][b]={a-1,b};
        else if(c=='R')pad[a][b]={a+1,b};
        else if(c=='U')pad[a][b]={a,b-1};
        else pad[a][b]={a,b+1};
        if(imposi[a][b]){
            // está encerrado desde hace tiempo
            cout << can << '\n';
            continue;
        }
        // esta encerrado si todo alrededor es imposi
    }
}