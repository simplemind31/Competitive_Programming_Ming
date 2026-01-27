#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,x,y,respu=1e18;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    freopen("reduce.in","r",stdin);
    freopen("reduce.out","w",stdout);
    cin >> n;
    if(n<=4){
        cout << 0;
        return 0;
    }
    pair<ll,ll> a[n],b[n];
    for(ll i=0;i<n;i++){
        cin >> x >> y;
        a[i]={x,i};
        b[i]={y,i};
    }
    sort(a,a+n);
    sort(b,b+n);
    for(ll i=0;i<=3;i++){
        for(ll j=0;j<=3;j++){
            if(i+j>3)continue;
            //quitar i a la iz y j a la de;
            for(ll ii=0;ii<=3;ii++){
                for(ll jj=0;jj<=3;jj++){
                    if(i+j+ii+jj!=3)continue;
                    ll quit[3]={-1,-1,-1};
                    ll now=0;
                    for(ll k=0;k<i;k++)quit[now++]=a[k].second;
                    for(ll k=0;k<j;k++)quit[now++]=a[n-1-k].second;
                    //quitar ii a la arriba y jj a la abajo;
                    ll con=0;
                    for(ll k=0;con<ii;k++){
                        if((b[k].second==quit[0])||(b[k].second==quit[1])||(b[k].second==quit[2]))continue;
                        quit[now++]=b[k].second;
                        con++;
                    }
                    con=0;
                    for(ll k=0;con<jj;k++){
                        if((b[n-1-k].second==quit[0])||(b[n-1-k].second==quit[1])||(b[n-1-k].second==quit[2]))continue;
                        quit[now++]=b[n-1-k].second;
                        con++;
                    }
                    ll arri=1e18,abb=0,izq=1e18,der=0;
                    for(ll fina=0;fina<n;fina++){
                        if(!(a[fina].second==quit[0]||a[fina].second==quit[1]||a[fina].second==quit[2])){
                            izq=min(izq,a[fina].first);
                            der=max(der,a[fina].first);
                        }
                        if(!(b[fina].second==quit[0]||b[fina].second==quit[1]||b[fina].second==quit[2])){
                            arri=min(arri,b[fina].first);
                            abb=max(abb,b[fina].first);
                        }
                    }
                    respu=min(respu,(der-izq)*(abb-arri));
                }
            }
        }
    }
    cout << respu;
}