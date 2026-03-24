#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n,m,fact[100001];
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
int solve(int a){
    int res=0;
    for(int i=0;i<=a/2;i++){
        res=(res+combi(a-i,i))%MOD;
    }
    return 2*res%MOD;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    fact[0]=1;
    for(int i=1;i<=100000;i++)fact[i]=1ll*fact[i-1]*i%MOD;
    cin >> n >> m;
    cout << (solve(n)+solve(m)-2)%MOD;
}
/*


101011001010
010100110101
101011001010


nc0,(n-1)c1,(n-2)c2,(n-3)c3
*/