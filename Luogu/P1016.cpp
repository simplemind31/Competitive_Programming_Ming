#include <bits/stdc++.h>
using namespace std;
double D1,C,D2,P,a,b,cost,conte;
int place,N;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> D1 >> C >> D2 >> P >> N;
    vector<pair<double,double>> gas(1);
    gas[0]={0,P};
    for(int i=1;i<=N;i++){
        cin >> a >> b;
        if(a<D1){
            gas.push_back({a,b});
        }
    }
    gas.push_back({D1,0});
    sort(gas.begin(),gas.end());
    N=gas.size();
    for(int i=1;i<N;i++){
        if(gas[i].first-gas[i-1].first>C*D2){
            cout << "No Solution";
            return 0;
        }
    }
    while(place!=N-1){
        int ideal=place;
        for(int i=place+1;i<N;i++){
            if(C*D2<gas[i].first-gas[place].first){
                break;
            }
            //alcanzable
            if(gas[i].second<gas[place].second){
                ideal=i;
                break;
            }
        }
        if(ideal==place){
            double mini=gas[place+1].second;
            ideal=place+1;
            //llegar al minimo de los alcanzables
            for(int i=place+2;i<N;i++){
                if(C*D2<gas[i].first-gas[place].first){
                    break;
                }
                if(gas[i].second<mini){
                    ideal=i;
                    mini=gas[i].second;
                    break;
                }
            }
            //llenar a full
            cost+=(C-conte)*gas[place].second;
            conte=C;
            conte-=(gas[ideal].first-gas[place].first)/D2;
            place=ideal;
        }else{
            //llegar a ideal
            //puedo llegar con lo que tengo?
            if(conte*D2>=gas[ideal].first-gas[place].first){
                conte-=(gas[ideal].first-gas[place].first)/D2;
                place=ideal;
            }else{
                //puedo ir una distancia de conte*D2
                cost+=(gas[ideal].first-gas[place].first-conte*D2)/D2*gas[place].second;
                place=ideal;
                conte=0;
            }
        }
    }
    cout << fixed << setprecision(2) << cost;
}