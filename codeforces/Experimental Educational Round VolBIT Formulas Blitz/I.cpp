#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll bigmod(ll b,int e){
    if(e<0)return 0;
    ll p=1;
    while(e){
        if(e&1)p=p*b;
        b=b*b;
        e>>=1;
    }
    return p;
}
int main(){
    scanf("%d",&n);
    printf("%I64d",4*2*3*bigmod(4,n-3)+4*3*3*bigmod(4,n-4)*(n-3));
}