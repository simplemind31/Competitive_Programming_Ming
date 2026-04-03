#include <bits/stdc++.h>
using namespace std;
int t,a,b;
int bigmod1(long double b,int e){
    long double p=1;
    while(e){
        if(e&1)p=p*b;
        while(p>=1000)p/=10;
        b=b*b;
        while(b>=1000)b/=10;
        e>>=1;
    }
    return p;
}
int bigmod2(int b,int e){
    int p=1;
    while(e){
        if(e&1)p=p*b%1000;
        b=b*b%1000;
        e>>=1;
    }
    return p;
}
int main(){
    cin >> t;
    while(t--){
        scanf("%d %d",&a,&b);
        printf("%d...%.03d\n",bigmod1(a,b),bigmod2(a%1000,b));
    }
}