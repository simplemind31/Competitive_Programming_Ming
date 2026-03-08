#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,q,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> q;
    ll mat[n+2];
    memset(mat,0,sizeof(mat));
    for(int i=1;i<=n;i++){
        cin >> a;
        mat[i]+=a;
        mat[i+1]-=a;
    }
    pair<pair<int,int>,int> queries[m+2];
    int con[m+2];
    memset(con,0,sizeof(con));
    for(int i=1;i<=m;i++){
        cin >> queries[i].first.first >> queries[i].first.second >> queries[i].second;
    }
    while(q--){
        cin >> a >> b;
        con[a]++;
        con[b+1]--;
    }
    for(int i=1;i<=m;i++){
        con[i]+=con[i-1];
        mat[queries[i].first.first]+=1ll*con[i]*queries[i].second;
        mat[queries[i].first.second+1]-=1ll*con[i]*queries[i].second;
    }
    for(int i=1;i<=n;i++){
        cout << (mat[i]+=mat[i-1]) << ' ';
    }
}