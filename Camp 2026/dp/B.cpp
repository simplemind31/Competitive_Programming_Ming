#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
vector<vector<ll>> mat;
vector<vector<ll>> memo;
// 2^n->n*m
ll solve(ll x,ll y){
    //memo[x][y]=cual es la máxima cantidad de suma que puedo conseguir si empiezo en la posicion (x,y)
    if(x>=n || y>=m){
        // se salio de mi matriz
        return -1e18;
    }
    // n-1,m-1 -> n-1,m-1
    if(x==n-1 && y==m-1)return mat[x][y];
    //memo[10][10]=100
    if(memo[x][y]!=-1e18)return memo[x][y];
    ll op1=solve(x+1,y);
    ll op2=solve(x,y+1);
    ll res=max(op1,op2)+mat[x][y];
    memo[x][y]=res;
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    mat.assign(n,vector<ll>(m));
    memo.assign(n,vector<ll>(m,-1e18));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }
    cout << solve(0,0);
}
// 10+3+4+15+6+1=39