#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
bitset<10000000> good;
int a,b,n,fact[1000001],res;
int bigmod(int b,int e){
    int p=1;
    while(e){
        if(e&1)p=1ll*p*b%MOD;
        e>>=1;
        b=1ll*b*b%MOD;
    }
    return p;
}
int inversemod(int a){
    return bigmod(a,MOD-2);
}
int combi(int a,int b){
    return 1ll*fact[a]*inversemod(1ll*fact[b]*fact[a-b]%MOD)%MOD;
}
void solvegood(int pos,int num){
    good[num]=true;
    if(pos==7)return;
    solvegood(pos+1,num*10+a);
    solvegood(pos+1,num*10+b);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    fact[0]=1;
    for(int i=1;i<=1000000;i++)fact[i]=1ll*fact[i-1]*i%MOD;
    cin >> a >> b >> n;
    solvegood(0,0);
    good[0]=false;
    for(int i=0;i<=n;i++){
        // hay i a y n-i bs
        int num=i*a+(n-i)*b;
        if(good[num]){
            res=(res+combi(n,i))%MOD;
        }
    }
    cout << res;
}