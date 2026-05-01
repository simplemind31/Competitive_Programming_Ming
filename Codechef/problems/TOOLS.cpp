#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll t,n;
pair<ll,ll> origen={0,0};
ll dist(pair<ll,ll>& x,pair<ll,ll>& y){return abs(x.first-y.first)+abs(x.second-y.second);}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        pair<pair<ll,ll>,pair<ll,ll>> cooks[n];
        ll dp[1<<n][n][n];
        for(ll i=0;i<n;i++)cin >> cooks[i].first.first >> cooks[i].first.second >> cooks[i].second.first >> cooks[i].second.second; 
        // si entregue al subset, termino en i, tengo tool j en la mano
        // llegue del subset^(1<<i)
        // necesitaba el tool i, si tenia tool i en la mano, entonces puedo 
        // - "agarrar un tool y llegar a i" -> quedo con el nuevo tool
        // - "no agarrar nada y llegar a i" -> quedo vacio
        // si no tenia tool i en la mano, entonces ir al tool i y recien al i
        // - quedo con el tool anterior
        // si tengo subset y no tengo nada agarrado-> puedo extenderlo de manera que 
        // - "agarro una cosa y lo llevo directo al cook" -> no tengo nada agarrado
        // - "agarrar dos cosas y llevar uno al cook" -> tengo el otro tool agarrado
        // agarrar a sí mismo es vacio
        //base case:
        // solo entregué a uno,
        fill(&dp[0][0][0],&dp[0][0][0]+(1<<n)*n*n,1e18);
        for(ll mask=0;mask<(1<<n);mask++){
            for(ll i=0;i<n;i++){
                if(!(mask&(1<<i)))continue;
                // no puedo terminar en i si el subset i no esta completado
                for(ll j=0;j<n;j++){
                    if(mask&(1<<j) && j!=i)continue;
                    // para que agarro tool j si ya se utilizó?
                    // entregue el subset mask, terminé en i y tengo el tool j agarrado
                    if(__builtin_popcount(mask)==1){
                        // - ir primero al tool j luego tool i y luego i
                        // - ir primero al tool i luego tool j y luego i
                        dp[mask][i][j]=min(dist(origen,cooks[j].second)+dist(cooks[j].second,cooks[i].second)+dist(cooks[i].second,cooks[i].first),dist(origen,cooks[i].second)+dist(cooks[i].second,cooks[j].second)+dist(cooks[j].second,cooks[i].first));
                    }else{
                        for(ll k=0;k<n;k++){
                            // llegue del k al i y tengo tool j en la mano
                            // entonces o k tenia tool i y agarro j para llegar a i
                            // o tenia el tool j agarrado en la mano y fui al tool i y luego a i
                            // o no tenia nada, fui a agarrar i y j y luego a i
                            if(!(mask&(1<<k)) || k==i)continue;
                            dp[mask][i][j]=min(dp[mask][i][j],dp[mask^(1<<i)][k][i]+dist(cooks[k].first,cooks[j].second)+dist(cooks[j].second,cooks[i].first));
                            dp[mask][i][j]=min(dp[mask][i][j],dp[mask^(1<<i)][k][j]+dist(cooks[k].first,cooks[i].second)+dist(cooks[i].second,cooks[i].first));
                            dp[mask][i][j]=min(dp[mask][i][j],dp[mask^(1<<i)][k][k]+min(dist(cooks[k].first,cooks[j].second)+dist(cooks[j].second,cooks[i].second)+dist(cooks[i].second,cooks[i].first),dist(cooks[k].first,cooks[i].second)+dist(cooks[i].second,cooks[j].second)+dist(cooks[j].second,cooks[i].first)));
                            // cuando j==i
                            dp[mask][i][i]=min(dp[mask][i][i],dp[mask^(1<<i)][k][i]+dist(cooks[k].first,cooks[i].first));
                        }
                    }
                }
            }
        }
        // minimo del dp[(1<<n)-1][i][i]+dist(cooks[i].first,origen) tal qu
        ll res=1e18;
        for(ll i=0;i<n;i++){
            res=min(res,dp[(1<<n)-1][i][i]+dist(cooks[i].first,origen));
        }
        cout << res << '\n';
    }
}
//8^4*2^8=2^12*2^8=2^20