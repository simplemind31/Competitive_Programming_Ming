#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,q,m,l,a,can[100];
vector<ll> nece[100];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i=0;i<n;i++){
        cin >> can[i];
        nece[i]=vector<ll>(n,0);
        nece[i][i]++;
    }
    cin >> q;
    while(q--){
        cin >> m >> l;
        nece[m-1]=vector<ll>(n,0);
        while(l--){
            cin >> a;
            nece[m-1][a-1]++;
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=i;j>=0;j--){
            //need nece[i][j] pero solo can[j]
            if(can[j]>=nece[i][j])continue;
            //cambiar nece[i][j]-can[j];
            ll need=nece[i][j]-can[j];
            for(ll k=j;k>=0;k--)nece[i][k]+=need*nece[j][k];
            nece[i][j]-=need;
        }
    }
    bool xd=true;
    while(xd){
        ll mini=1e9;
        for(ll i=0;i<n;i++){
            if(nece[n-1][i]==0)continue;
            mini=min(mini,can[i]/nece[n-1][i]);
            if(nece[n-1][i]>can[i]){
                xd=false;
                break;
            }
        }
        can[n-1]+=mini;
        for(int i=0;i<n;i++){
            if(nece[n-1][i]==0)continue;
            can[i]-=mini*nece[n-1][i];
            if(can[i]!=0)continue;
            //todo lo que necesita i hay que cambiar
            for(ll j=n-1;j>=0;j--){
                int need=nece[j][i];
                for(int k=n-1;k>=0;k--)nece[j][k]+=nece[j][i]*nece[i][k];
                nece[j][i]-=need;
            }
        }
        //ajustar? si es mayor
        //no se si es necesario esto
        for(ll i=0;i<n;i++){
            for(ll j=i;j>=0;j--){
                //need nece[i][j] pero solo can[j]
                if(can[j]>=nece[i][j])continue;
                //cambiar nece[i][j]-can[j];
                ll need=nece[i][j]-can[j];
                for(ll k=j;k>=0;k--)nece[i][k]+=need*nece[j][k];
                nece[i][j]-=need;
            }
        }
    }
    cout << can[n-1];
}