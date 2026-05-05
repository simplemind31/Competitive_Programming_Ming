#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,now;
vector<vector<char>> mat;
vector<vector<ll>> dist[3];
deque<pair<ll,ll>> cola;
void solve(ll nowx,ll nowy,ll nex,ll ney){
    if(nex<0 || nex>=n || ney<0 || ney>=m)return;
    if(mat[nex][ney]=='#')return;
    ll dis=dist[now][nowx][nowy]+(mat[nex][ney]=='.');
    if(dis<dist[now][nex][ney]){
        if(mat[nex][ney]!='.')cola.push_front({nex,ney});
        else cola.push_back({nex,ney});
        dist[now][nex][ney]=dis;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    mat.assign(n,vector<char>(m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }
    for(ll i=0;i<3;i++){
        dist[i].assign(n,vector<ll>(m,1e9));
    }
    for(ll i=0;i<3;i++){
        now=i;
        for(ll j=0;j<n;j++){
            for(ll k=0;k<m;k++){
                if(mat[j][k]-'0'==now+1){
                    dist[i][j][k]=0;
                    cola.push_back({j,k});
                }
            }
        }
        while(!cola.empty()){
            pair<ll,ll> top=cola.front();
            cola.pop_front();
            solve(top.first,top.second,top.first-1,top.second);
            solve(top.first,top.second,top.first+1,top.second);
            solve(top.first,top.second,top.first,top.second-1);
            solve(top.first,top.second,top.first,top.second+1);
        }
    }
    ll mini=1e9;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(mat[i][j]=='.')mini=min(mini,dist[0][i][j]+dist[1][i][j]+dist[2][i][j]-2);
            else if(mat[i][j]!='#')mini=min(mini,dist[0][i][j]+dist[1][i][j]+dist[2][i][j]);
        }
    }
    if(mini==1e9)mini=-1;
    cout << mini;
}