#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;
int n,m,last;
matrix Abx;
ll exp(ll b,ll e){
    ll p=1;
    for(;e;e>>=1,b=b*b%MOD)if(e&1)p=p*b%MOD;
    return p;
}
ll inversemod(ll b){return exp(b,MOD-2);}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    m++;
    Abx.assign(n,vector<ll>(m));
    vector<int> pospivot(m,-1);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin >> Abx[i][j];
    for(int i=0;i<m-1 && last<n;i++){
        // make this col pivot on last
        for(int j=last;j<n;j++){
            if(Abx[j][i]){
                swap(Abx[j],Abx[last]);
                break;
            }
        }
        if(!Abx[last][i])continue;// no existe pivot
        // make the row last *inversemod
        ll inv=inversemod(Abx[last][i]);
        for(int j=i;j<m;j++)Abx[last][j]=Abx[last][j]*inv%MOD;
        for(int j=0;j<n;j++){
            if(j==last)continue;
            ll val=Abx[j][i];
            for(int k=i;k<m;k++)Abx[j][k]=(Abx[j][k]-val*Abx[last][k]%MOD+MOD)%MOD;
        }
        pospivot[i]=last++;
    }
    // alguna fila 0=x donde x!=0?
    for(int i=0;i<n;i++){
        bool xd=false;
        for(int j=0;j<m-1 && !xd;j++)if(Abx[i][j])xd=true;
        if(!xd && Abx[i][m-1]){
            cout << -1;
            return 0;
        }
    }
    for(int i=0;i<m-1;i++){
        if(pospivot[i]==-1)cout << "0 ";
        else cout << Abx[pospivot[i]][m-1] << ' ';
    }
}