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
    for(int i=0;i<n;i++){
        cin >> blue[i].first >> blue[i].second;
        mcd=gcd(mcd,blue[i].second);
        suma+=blue[i].first;
    }
    if(mcd>suma){
        cout << "N";
        return 0;
    }
    // abs(ga-gb)%mcd==0
    vector<bool> posible(suma+1);
    posible[0]=true;
    for(int i=0;i<n;i++){
        for(int j=suma;j>=blue[i].first;j--){
            if(posible[j-blue[i].first])posible[j]=true;
            if(abs(j-(suma-j))%mcd==0 && (posible[j] || posible[suma-j])){
                cout << "Y";
                return 0;
            }
        }
    }
    cout << "N";
}