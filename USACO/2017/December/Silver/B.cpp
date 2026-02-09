#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,G,now=1,can[100001],con;
template<typename A,typename B>istream& operator>>(istream& in,pair<A,B>& par){
    in >> par.first >> par.second;
    return in;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("measurement.in","r",stdin);
    freopen("measurement.out","w",stdout);
    cin >> n >> G;
    pair<int,pair<int,int>> cows[n];
    set<pair<int,int>> ayu;
    map<int,int> clav;
    for(int i=0;i<n;i++){
        cin >> cows[i];
        if(clav[cows[i].second.first]==0)clav[cows[i].second.first]=now++;
        cows[i].second.first=clav[cows[i].second.first];
    }
    for(int i=0;i<=100000;i++){
        can[i]=G;
        ayu.insert({G,i});
    }
    ayu.insert({G,-1});
    sort(cows,cows+n);
    for(int i=0;i<n;i++){
        if(can[cows[i].second.first]==(--ayu.end())->first){
            if((----ayu.end())->first==(--ayu.end())->first){
                // no es unico
                // de todas maneras cambia
                con++;
                ayu.erase({can[cows[i].second.first],cows[i].second.first});
                can[cows[i].second.first]+=cows[i].second.second;
                ayu.insert({can[cows[i].second.first],cows[i].second.first});
            }else{
                //unico mayor
                ayu.erase({can[cows[i].second.first],cows[i].second.first});
                can[cows[i].second.first]+=cows[i].second.second;
                ayu.insert({can[cows[i].second.first],cows[i].second.first});
                if((--ayu.end())->first==can[cows[i].second.first]){
                    // sigue siendo el mayor
                    // es unico mayor?
                    if((----ayu.end())->first==can[cows[i].second.first]){
                        // no es unico
                        con++;
                    }else{
                        //sigue siendo unico, no cambia nada
                    }
                }else{
                    // ya no es mayor
                    con++;
                }
            }
        }else{
            // no es mayor, solo cambia si es mayor
            ayu.erase({can[cows[i].second.first],cows[i].second.first});
            can[cows[i].second.first]+=cows[i].second.second;
            ayu.insert({can[cows[i].second.first],cows[i].second.first});
            if((--ayu.end())->first==can[cows[i].second.first])con++;
        }
    }
    cout << con;
}