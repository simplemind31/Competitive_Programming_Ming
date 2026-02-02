#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,l,r,k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> l >> r >> k;
    vector<pair<pair<ll,ll>,ll>> swimmer(k);
    set<ll> imposi;
    for(int i=0;i<k;i++){
        cin >> swimmer[i].first.first >> swimmer[i].first.second >> swimmer[i].second;
        // tardo swimmer[i].first.second+1 segundos llegar a este lane
        // swimmer[i] habra viajado (swimmer[i].first.second+1)*swimmer[i].second de distancia;
        // en que x es esa distancia?
        ll dist=(swimmer[i].first.second+1)*abs(swimmer[i].second);
        // cada 2*(n-1) de distancia llega al mismo estado
        dist%=2*(n-1);
        if(swimmer[i].second<=0){
            // mueve abajo;
            if(n-1>swimmer[i].first.first+dist){
                swimmer[i].first.first+=dist;
                dist=0;
            }else{
                dist-=n-1-swimmer[i].first.first;
                swimmer[i].first.first=n-1;
                // volver arriba
                if(n-1>dist){
                    swimmer[i].first.first-=dist;
                    dist=0;
                }else{
                    dist-=n-1;
                    swimmer[i].first.first=0;
                    // volver abajo
                    swimmer[i].first.first+=dist;
                    dist=0;
                }
            }
        }else{
            // mueve arriba
            if(swimmer[i].first.first-dist>0){
                swimmer[i].first.first-=dist;
                dist=0;
            }else{
                dist-=swimmer[i].first.first;
                swimmer[i].first.first=0;
                if(swimmer[i].first.first+dist<n-1){
                    swimmer[i].first.first+=dist;
                    dist=0;
                }else{
                    dist-=n-1;
                    swimmer[i].first.first=n-1;

                    swimmer[i].first.first-=dist;
                    dist=0;
                }
            }
        }
        //cout << swimmer[i].first.first << '\n';
        // cuando yo llego a este lane, este swimmer esta en seimmer[i].first.first;
        // entonces no puedo venir a este lugar
        if(swimmer[i].first.first>=l && swimmer[i].first.first<=r)imposi.insert(swimmer[i].first.first);
    }
    cout << r-l+1-imposi.size();
}
//2:20