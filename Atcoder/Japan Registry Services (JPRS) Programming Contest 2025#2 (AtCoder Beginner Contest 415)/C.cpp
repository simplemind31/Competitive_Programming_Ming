#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,tot;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> st;
        tot=1<<n;
        vector<bool> pos(tot);
        pos[0]=true;
        for(int i=1;i<tot;i++)if(st[i-1]=='0')for(int j=0;j<n&&!pos[i];j++)pos[i]=(i&(1<<j))&&pos[i-(1<<j)];
        cout << (pos[tot-1]?"Yes":"No") << '\n';
    }
}