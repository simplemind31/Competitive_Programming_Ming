#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;
int t,n,m,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        int maxi[n+1][m+1],mini[n+1][m+1];
        fill(&maxi[0][0],&maxi[0][0]+(n+1)*(m+1),-1e9);
        fill(&mini[0][0],&mini[0][0]+(n+1)*(m+1),1e9);
        maxi[0][1]=maxi[1][0]=mini[0][1]=mini[1][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> a;
                maxi[i][j]=max(maxi[i-1][j],maxi[i][j-1])+a;
                mini[i][j]=min(mini[i-1][j],mini[i][j-1])+a;
            }
        }
        if((!((n+m)&1)) || maxi[n][m]<0 || mini[n][m]>0)cout << "NO\n";
        else cout << "YES\n";
    }
}
