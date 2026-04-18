#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,m,a,b,o;
ll dp[101][101][102];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> o;
    vector<pair<ll,ll>> cuartos(n);
    vector<pair<ll,ll>> ofertas(m);
    for(ll i=0;i<n;i++)cin >> cuartos[i].second >> cuartos[i].first;
    for(ll i=0;i<m;i++)cin >> ofertas[i].second >> ofertas[i].first;
    sort(ALL(cuartos));
    sort(ALL(ofertas));
    // si una oferta puede el cuarto en pos i, entonces puede todos cuartos en pos>=i
    // two poller
    ll j=0;
    for(ll i=0;i<m;i++){
        while(j<n && ofertas[i].first>cuartos[j].first)j++;
        ofertas[i].first=j;
    }
    // eliminar los que están fuera del limite
    while(!ofertas.empty() && ofertas.back().first>=n)ofertas.pop_back();
    m=ofertas.size();
    /*for(ll i=0;i<n;i++){
        cout << cuartos[i].first << ' ';
    }
    cout << endl;
    for(ll i=0;i<n;i++){
        cout << cuartos[i].second << ' ';
    }
    cout << endl;
    for(ll i=0;i<m;i++){
        cout << ofertas[i].first << ' ';
    }
    cout << endl;
    for(ll i=0;i<m;i++){
        cout << ofertas[i].second << ' ';
    }*/
    // encontrar una forma de maximizar
    // ir para cuartos de menor a mayor, ver quienes ofrecen, y cual es el máximo
    // pero solo podemos elegir o
    // mejor forma si tengo los primeros j ofertas para las primeras i cuartos y con k matches
    ll res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<=o;k++){
                // no hago nada con i
                dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);
                // no hago nada con j
                dp[i][j+1][k]=max(dp[i][j+1][k],dp[i][j][k]);
                // puedo matchear i con j?
                if(ofertas[j].first<=i){
                    // si puedo
                    dp[i+1][j+1][k+1]=max(dp[i+1][j+1][k+1],dp[i][j][k]+ofertas[j].second-cuartos[i].second);
                }
            }
        }
    }
    for(int k=0;k<=o;k++)res=max(res,dp[n][m][k]);
    cout << res;
}