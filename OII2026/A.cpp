#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,ans,sumaactual,t,R;
vector<ll> respuestas;
void solve(ll l,ll r,ll suma){
    //la suma de numeros entre l y r debe ser suma
    if(suma==0)return;
    if(suma==(l+r)*(r-l+1)/2){
        for(int i=l;i<=r;i++){
            respuestas.push_back(i);
            sumaactual+=i;
        }
        return;
    }
    ll mid=(l+r)>>1;
    cout << "? " << mid << endl;
    cout.flush();
    ll deberia=(1+mid)*mid/2;
    cin >> ans;
    // la suma desde 1 a mid es ans;
    ll nosesuma=deberia-ans;
    // la suma de los fakes de 1 al mid es nosesuma,
    // quitamos los actuales
    ll sumaiz=nosesuma-sumaactual;
    ll sumade=suma-sumaiz;
    solve(l,mid,sumaiz);
    solve(mid+1,r,sumade);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // si puedo encontrar la suma de 1 a i,
    /*
    el problema basicamente es elegir k numeros tal que su suma es igual al query
    cuando preunto en pos x, enotnces puedo saber la suma de nuemros en [l,x] y en [x+1,r]
    binary search?
    */
    cin >> t;
    while(t--){
        respuestas.clear();
        sumaactual=0;
        cin >> n >> k;
        cout << "? " << n << endl;
        cout.flush();
        ll deberia=n*(n+1)/2;
        cin >> ans;
        solve(1,n,deberia-ans);
        cout << "! ";
        for(auto u:respuestas)cout << u << ' ';
        cout << endl;
        cout.flush();
        cin >> R;
    }
}