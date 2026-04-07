#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector<vector<int>> dist(n,vector<int>(n,1e9));
    while(m--){
        cin >> a >> b >> c;
        dist[--a][--b]=c;
        dist[b][a]=c;
    }
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            for(int j=0;j<n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    for(int i=1;i<n;i++)cout << ((dist[0][i]==1e9)?-1:dist[0][i]) << '\n';
}