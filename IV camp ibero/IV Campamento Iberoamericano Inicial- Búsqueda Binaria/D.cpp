#include <bits/stdc++.h>
using namespace std;
long long n,t;
int main(){
    scanf("%lld%lld",&n,&t);
    vector<long long> maquina(n);
    for(long long i=0;i<n;i++){
        scanf("%lld",&maquina[i]);
    }
    long long l=1,r=1e18;
    while(l<r){
        long long mid=(l+r)/2;
        long long cantidad_productos=0;
        for(int i=0;i<n;i++){
            cantidad_productos+=mid/maquina[i];
            if(cantidad_productos>=t){
                break;
            }
        }
        if(cantidad_productos>=t){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    printf("%lld",l);
}