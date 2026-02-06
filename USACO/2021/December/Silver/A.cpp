#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,m;
ll res,last=-1e18;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> k >> m >> n;
    pair<ll,ll> points[k+m];
    // position, val//-1=Njoh
    for(int i=0;i<k;i++)cin >> points[i].first >> points[i].second;
    for(int i=0;i<m;i++){
        cin >> points[i+k].first;
        points[i+k].second=-1;
    }
    sort(points,points+(m+=k));
    ll dist[m];
    for(int i=0;i<m;i++)dist[i]=1e18;
    for(int i=0;i<m;i++){
        if(points[i].second==-1)last=points[i].first;
        dist[i]=points[i].first-last;
    }
    last=1e18;
    for(int i=m-1;i>=0;i--){
        if(points[i].second==-1)last=points[i].first;
        dist[i]=min(dist[i],last-points[i].first);
    }
    // ya tengo distancia de cada uno al njoh mas cerca
    int first=-1;
    vector<pair<int,int>> pares;
    for(int i=0;i<m;i++){
        if(points[i].second==-1){
            if(first!=-1){
                pares.push_back({first,i-1});
                first=-1;
            }
            continue;
        }
        if(first==-1)first=i;
    }
    if(first!=-1)pares.push_back({first,m-1});
    //analizar por par, es mejor poner a la izquierda o derecha?
    vector<ll> orden;
    for(auto &[u,v]:pares){
        // checkear si pongo a la izquierda
        ll sumaiz=0,sumade=0;
        // poner en points[u].first+dist[u]-0.5
        // minimo a la iz= points[i].first-dist[i]+0.5, iz<=u?
        for(int i=u;i<=v;i++)if(points[i].first-dist[i]+1<=points[u].first+dist[u])sumaiz+=points[i].second;
        //check si pongo a la derecha
        // points[v]-dist[v]+0.5,maximo a la derecha=points[i].first+dist[i]-0.5
        for(int i=v;i>=u;i--)if(points[i].first+dist[i]-1>=points[v].first-dist[v])sumade+=points[i].second;
        // quitar al menor lo que pertenece al mayor
        if(sumaiz>=sumade){
            for(int i=v;i>=u;i--)if(points[i].first+dist[i]-1>=points[v].first-dist[v] && points[i].first-dist[i]+1<=points[u].first+dist[u])sumade-=points[i].second;
        }else{
            for(int i=u;i<=v;i++)if(points[i].first-dist[i]+1<=points[u].first+dist[u] && points[i].first+dist[i]-1>=points[v].first-dist[v])sumaiz-=points[i].second;
        }
        orden.push_back(sumaiz);
        orden.push_back(sumade);
    }
    sort(orden.begin(),orden.end());
    while(!orden.empty() && n--){
        res+=orden.back();
        orden.pop_back();
    }
    cout << res;
}