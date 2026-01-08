#include <bits/stdc++.h>
using namespace std;
int n,q,pad[200001][20],a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for(int i=2;i<=n;i++){
        cin >> a;
        pad[i][0]=a;
    }
    for(int i=1;i<20;i++)for(int j=0;j<=n;j++)pad[j][i]=pad[pad[j][i-1]][i-1];
    while(q--){
        cin >> a >> b;
        for(int i=0;i<20;i++)if(b&(1<<i))a=pad[a][i];
        cout << ((a==0)?-1:a) << '\n';
    }
}