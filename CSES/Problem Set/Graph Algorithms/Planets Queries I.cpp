#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,ne[200001][30],a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++)cin >> ne[i][0];
    for(int j=1;j<30;j++)for(int i=1;i<=n;i++)ne[i][j]=ne[ne[i][j-1]][j-1];
    while(q--){
        cin >> a >> b;
        for(int j=29;j>=0;j--)if(b&(1<<j))a=ne[a][j];
        cout << a << '\n';
    }
}