#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
bool posi[500][500],usado[500];
ll n,m,r,t,k,a,b,queda[500];
vector<ll> resuelve[500],resolvido[500];
vector<ll> res[500];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin >> n >> m >> r >> t >> k;
    t/=r;
    for(ll i=0;i<n;i++)queda[i]=t;
    // cada persona resuelve a lo mucho t problems
    // ordenar task por cantidad de gente que lo resuelve(ascen) y persona por la cantidad que sobra
    while(k--){
        cin >> a >> b;
        posi[--a][--b]=true;
        resuelve[a].push_back(b);
        resolvido[b].push_back(a);
    }
    /*priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> cola;
    for(ll i=0;i<m;i++){
        cola.push({resolvido[i].size(),i});
    }*/
   // si existe personas que tienen a lo mucho t resuelve usarlos todos
    int permuta[m];
    for(int i=0;i<m;i++){
        permuta[i]=i;
    }
    shuffle(permuta,permuta+m,rng);
    /*for(int i=0;i<m;i++){
        cout << permuta[i] << ' ';
    }*/
    while(true){
        ll ind=-1,can=1e9;
        for(ll i=0;i<m;i++){
            if(usado[permuta[i]])continue;
            ll con=0;
            for(auto u:resolvido[permuta[i]]){
                if(queda[u])con++;
            }
            if(con>0 && con<can){
                can=con;
                ind=permuta[i];
            }
        }
        if(ind==-1)break;
        // elegir el que tiene mas opciones
        ll person=-1;
        can=0;
        for(auto u:resolvido[ind]){
            if(!queda[u])continue;
            ll con=0;
            for(auto v:resuelve[u]){
                if(!usado[v])con++;
            }
            if(con>can){
                person=u;
                can=con;
            }
        }
        // person resuelve ind
        res[person].push_back(ind);
        usado[ind]=true;
        queda[person]--;
    }
    vector<pair<pair<ll,ll>,ll>> superres;
    ll suma=0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<res[i].size();j++){
            suma+=(j+1)*r;
            superres.push_back({{i,res[i][j]},j*r});
        }
    }
    cout << superres.size() << ' ' << suma << '\n';
    for(auto u:superres){
        cout << u.first.first+1 << ' ' << u.first.second+1 << ' ' << u.second << '\n';
    }
}