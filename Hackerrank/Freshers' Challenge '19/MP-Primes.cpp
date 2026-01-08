#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll a,b,con;
bitset<10000001> criba;
vector<ll> primos;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    criba[0]=criba[1]=1;
    for(ll i=4;i<=10000000;i+=2){
        criba[i]=1;
    }
    for(ll i=3;i*i<=10000000;i+=2){
        if(!criba[i]){
            for(ll j=i+i;j<=10000000;j+=i){
                criba[j]=1;
            }
        }
    }
    for(ll i=0;i<=10000000;i++){
        if(!criba[i]){
            primos.push_back(i);
        }
    }
    cin >> a >> b;
    vector<ll> ayu={2,4,6,10,12,16,18,22,28,30,36,40,42,46,52};
    // todo a<=x^ayu[i]<=b;
    for(int i=0;i<ayu.size();i++){
        for(int j=0;j<primos.size();j++){
            ll prod=1;
            for(int k=0;k<ayu[i];k++){
                prod*=primos[j];
                if(prod>b){
                    break;
                }
            }
            if(prod>=a && prod<=b){
                con++;
            }
        }
    }
    cout << con;
}