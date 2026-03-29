#include <bits/stdc++.h>
using namespace std;
int n,m,t,mcd,suma;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    if(n==1){
        cout << "N";
        return 0;
    }
    pair<int,int> blue[n];
    vector<int> con(200001);
    bitset<200001> posi;
    posi[0]=1;
    for(int i=0;i<n;i++){
        cin >> blue[i].first >> blue[i].second;
        con[blue[i].first]++;
        mcd=gcd(blue[i].second,mcd);
        suma+=blue[i].first;
    }
    int con0=con[0];
    // abs(ga-gb)%mcd==0
    for(int i=1;i<=200000;i++){
        for(int j=0;(1<<j)<=con[i];j++){
            posi|=(posi<<((1<<j)*i));
            con[i]-=(1<<j);
        }
        if(con[i])posi|=(posi<<(con[i]*i));
    }
    for(int i=1;i<suma;i++){
        if(posi[i] && abs(suma-2*i)%mcd==0){
            cout << "Y";
            return 0;
        }
    }
    if(suma%mcd==0 && con0)cout << "Y";
    else cout << "N";
}