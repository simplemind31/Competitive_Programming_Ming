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
        if(can[i]>0)continue;
        for(ll j=i;j>=0;j--){
            //need nece[i][j] pero solo can[j]
            if(can[j]>=nece[i][j])continue;
            //cambiar nece[i][j]-can[j];
            ll need=nece[i][j]-can[j];
            //if(i==4)cout << nece[i][j] << ' ';
            //if(i==4)cout << j << ' ';
            nece[i][j]-=need;
            for(ll k=j;k>=0;k--){
                nece[i][k]+=need*nece[j][k];
                //if(i==2 && k==0)cout << nece[i][k] << ' ';
                if(nece[i][k]>=1e9)nece[i][k]=1e9;
                //if(i==4 && k==0)cout << nece[i][j] << ' ';
            }
            //if(i==2 && j==0)cout << nece[i][j] << ' ';
            //if(i==2 && j==0)cout << nece[i][j] << ' ';
        }
    }
    cout << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << nece[i][j] << ' ';
        }
        cout << '\n';
    }
    /*while(true){
        ll mini=1e9;
        for(ll i=0;i<n;i++){
            if(nece[n-1][i]==0)continue;
            mini=min(mini,can[i]/nece[n-1][i]);
        }
    }*/
}