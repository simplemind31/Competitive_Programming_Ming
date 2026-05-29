#include <bits/stdc++.h>
using namespace std;
int n,m,pos[1000000],a,b;
struct cmp{
    bool operator()(const pair<int,int>& x,const pair<int,int>& y)const{
        if((x.second-x.first)/2==(y.second-y.first)/2)return x.first<y.first;
        return (x.second-x.first)/2>(y.second-y.first)/2;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    memset(pos,-1,sizeof(pos));
    cin >> n >> m;
    set<pair<int,int>,cmp> setdistan;
    set<pair<int,int>> setnormal;
    while(m--){
        cin >> a >> b;
        b--;
        if(a==1){
            // insertar b
            if(setdistan.empty()){
                cout << (pos[b]=1) << '\n';
                setdistan.insert({1,1});
                setnormal.insert({1,1});
                continue;
            }
            if(setdistan.begin()->first==setdistan.begin()->second){
                // poner o adelante o atras
                int temp=setdistan.begin()->first;
                setdistan.clear();
                setnormal.clear();
                if(temp-1>=n-temp){
                    pos[b]=1;
                    setdistan.insert({1,temp});
                    setnormal.insert({1,temp});
                }else{
                    pos[b]=n;
                    setdistan.insert({temp,n});
                    setnormal.insert({temp,n});
                }
                cout << pos[b] << '\n';
                continue;
            }
            // considerar poner adelante o atras
            pair<int,int> entre=*setdistan.begin();
            int mid=(entre.first+entre.second)>>1;
            if(setnormal.begin()->first-1>=mid-entre.first){
                if(setnormal.begin()->first-1>=n-prev(setnormal.end())->second){
                    // poner 1
                    pos[b]=1;
                    setdistan.insert({1,setnormal.begin()->first});
                    setnormal.insert({1,setnormal.begin()->first});
                }else{
                    // poner n
                    pos[b]=n;
                    setdistan.insert({prev(setnormal.end())->second,n});
                    setnormal.insert({prev(setnormal.end())->second,n});
                }
            }else{
                if(mid-entre.first>=n-prev(setnormal.end())->second){
                    //poner mid
                    pos[b]=mid;
                    setnormal.insert({entre.first,mid});
                    setnormal.insert({mid,entre.second});
                    setdistan.insert({entre.first,mid});
                    setdistan.insert({mid,entre.second});
                    setnormal.erase(entre);
                    setdistan.erase(entre);
                }else{
                    //poner n
                    pos[b]=n;
                    setdistan.insert({prev(setnormal.end())->second,n});
                    setnormal.insert({prev(setnormal.end())->second,n});
                }
            }
            cout << pos[b] << '\n';
        }else{
            int mid=pos[b];
            pos[b]=-1;
            if(setnormal.begin()->first==setnormal.begin()->second){
                setnormal.clear();
                setdistan.clear();
                continue;
            }
            if(setnormal.size()==1){
                // quitar ese punto
                int suma=setnormal.begin()->first+setnormal.begin()->second;
                setnormal.clear();
                setdistan.clear();
                setnormal.insert({suma-mid,suma-mid});
                setdistan.insert({suma-mid,suma-mid});
                continue;
            }
            auto desp=setnormal.lower_bound({mid,mid});
            if(desp==setnormal.end()){
                // desp es el ultimo punto
                // quitar este punto
                desp--;
                setdistan.erase(*desp);
                setnormal.erase(*desp);
                continue;
            }else if(desp==setnormal.begin()){
                // desp es el primer punto
                setdistan.erase(*desp);
                setnormal.erase(*desp);
                continue;
            }
            // eliminar los dos y unirlos en uno
            auto ante=prev(desp);
            int puntoante=ante->first;
            int puntodesp=desp->second;
            setnormal.erase({puntoante,mid});
            setnormal.erase({mid,puntodesp});
            setdistan.erase({puntoante,mid});
            setdistan.erase({mid,puntodesp});
            setnormal.insert({puntoante,puntodesp});
            setdistan.insert({puntoante,puntodesp});
        }
    }
}