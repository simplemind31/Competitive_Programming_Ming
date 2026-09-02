#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,n,d,p,a,b;
vector<vector<int>> graph,importante,notimportante,copyim,copynot;
vector<pair<int,int>> frente,fondo,mid;
bool dfs(int node,int pad){
    while(!copyim[node].empty()){
        int ulti=copyim[node].back();
        if(ulti==pad){
            copyim[node].pop_back();
            continue;
        }
        if(copynot[node].empty())return false;
        if(copynot[node].back()==pad){
            copynot[node].pop_back();
            continue;
        }
        frente.push_back({node,ulti});
        fondo.push_back({node,copynot[node].back()});
        if(!dfs(ulti,node))return false;
        copyim[node].pop_back();
        copynot[node].pop_back();
    }
    while(copynot[node].size()>=2){
        if(copynot[node].back()==pad){
            copynot[node].pop_back();
            continue;
        }
        frente.push_back({node,copynot[node].back()});
        copynot[node].pop_back();
        fondo.push_back({node,copynot[node].back()});
        copynot[node].pop_back();
    }
    while(copynot[node].size()){
        if(copynot[node].back()==pad){
            copynot[node].pop_back();
            continue;
        }
        mid.push_back({node,copynot[node].back()});
        copynot[node].pop_back();
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    while(t--){
        frente.clear();
        fondo.clear();
        mid.clear();
        cin >> p >> n;
        if(p==1){
            cin >> d;
            if(d==1){
                if(n>2)cout << "NO\n";
                else cout << "YES\n1 2\n";
                continue;
            }
            // como diametro es d, entonces ny no podemos usar extremos entonces usamos d-2;
            d-=2;
            d++;
            int ne=d+1;
            for(int i=1;i<d;i++){
                frente.push_back({i,i+1});
                fondo.push_back({i,ne++});
            }
            if(n&1){
                frente.push_back({d,ne++});
                fondo.push_back({d,ne++});
            }else{
                mid.push_back({d,ne++});
            }
            while(frente.size()+fondo.size()+mid.size()<n-1){
                frente.push_back({d,ne++});
                fondo.push_back({d,ne++});
            }
            if(frente.size()+fondo.size()+mid.size()!=n-1){
                cout << "NO\n";
                continue;
            }
            reverse(ALL(fondo));
            cout << "YES\n";
            for(auto u:frente)cout << u.first << ' ' << u.second << '\n';
            for(auto u:mid)cout << u.first << ' ' << u.second << '\n';
            for(auto u:fondo)cout << u.first << ' ' << u.second << '\n';
            continue;
        }
        /*
        como es palidromo si n es impar, enotnces habra par en el palidromo, 
        entonces cada nodeo sera usado par veces
        de lo contrario habra un medio
        */
        // encontrar un nodo para expandir pero cual?
        // encontrar el más largo?
        // cualquier que no sea hoja?
        if(n==1){
            cout << "YES\n1 2\n";
            continue;
        }
        importante.clear();
        notimportante.clear();
        graph.clear();
        graph.resize(n);
        importante.resize(n);
        notimportante.resize(n);

        copyim.clear();
        copynot.clear();
        copyim.resize(n);
        copynot.resize(n);
        for(int i=1;i<n;i++){
            cin >> a >> b;
            graph[--a].push_back(--b);
            graph[b].push_back(a);
        }
        for(int i=0;i<n;i++){
            for(auto u:graph[i]){
                if(graph[u].size()!=1)importante[i].push_back(u);
                else notimportante[i].push_back(u);
            }
        }
        bool xd=false;
        for(int i=0;i<n && !xd;i++){
            frente.clear();
            fondo.clear();
            mid.clear();
            for(int j=0;j<n;j++){
                copyim[j]=importante[j];
                copynot[j]=notimportante[j];
            }
            if(dfs(i,-1)){
                if(mid.size()<=1){
                    reverse(ALL(fondo));
                    cout << "YES\n";
                    for(auto u:frente)cout << u.first+1 << ' ' << u.second+1 << '\n';
                    for(auto u:mid)cout << u.first+1 << ' ' << u.second+1 << '\n';
                    for(auto u:fondo)cout << u.first+1 << ' ' << u.second+1 << '\n';
                    xd=true;
                }
            }
        }
        if(!xd){
            cout << "NO\n";
        }
    }
}