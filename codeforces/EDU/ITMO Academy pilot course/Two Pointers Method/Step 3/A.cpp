#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> s;
    ll j=-1,nums[n],mini=1e18,ciclo=0,suma=0,pos=-1;
    for(int i=0;i<n;i++){
        cin >> nums[i];
        ciclo+=nums[i];
    }
    // empieza en i y termina en j;
    ll can=s/ciclo;
    s%=ciclo;
    if(s==0){
        cout << 1 << ' ' << n*can;
        return 0;
    }
    while(suma<s){
        j=(j+1)%n;
        suma+=nums[j];
    }
    for(int i=0;i<n;i++){
        if(j<i){
            if(j+1+n-i<mini){
                pos=i;
                mini=j+1+n-i;
            }
        }else{
            if(j-i+1<mini){
                pos=i;
                mini=j-i+1;
            }
        }
        suma-=nums[i];
        while(suma<s){
            j=(j+1)%n;
            suma+=nums[j];
        }
    }
    cout << pos+1 << ' ' << can*n+mini;
}