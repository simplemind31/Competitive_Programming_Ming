#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll k,res[1001],tam,con,fin,combi[1001][1001];
string n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    res[0]=1e9;
    res[1]=0;
    for(int i=2;i<=1000;i++)res[i]=res[__builtin_popcount(i)]+1;
    for(int i=0;i<=1000;i++){
        combi[i][0]=combi[i][i]=1;
        for(int j=1;j<i;j++)combi[i][j]=(combi[i-1][j]+combi[i-1][j-1])%MOD;
    }
    cin >> n >> k;
    if(k==0){
        cout << 1;
        return 0;
    }else if(k==1){
        cout << n.size()-1;
        return 0;
    }
    tam=n.size();
    for(ll i=0;i<tam;i++){
        if(n[i]=='0')continue;
        //elegir primero 0 u elegir 1 atras
        //ver entre 0 y tam-i-1;
        //if(res[con]==k)fin++;
        for(ll j=0;j<=tam-i-1;j++){
            if(res[con+j]+1==k){
                //combinacion de tam-i-1 en j
                fin=(fin+combi[tam-i-1][j])%MOD;
            }
        }
        con++;
    }
    if(res[con]+1==k)fin++;
    cout << fin;
}