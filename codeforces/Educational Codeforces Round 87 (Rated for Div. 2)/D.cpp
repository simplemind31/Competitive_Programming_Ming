#include <bits/stdc++.h>
#define LsOne(x) x&(-x)
using namespace std;
int n,m,a,con[1000001],BIT[1000001],can;
int sum(int pos){
    int suma=0;
    while(pos>0){
        suma+=BIT[pos];
        pos-=LsOne(pos);
    }
    return suma;
}
void update(int pos,int val){
    while(pos<=n){
        BIT[pos]+=val;
        pos+=LsOne(pos);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    m+=n;
    int LOG=log2(n);
    while(m--){
        cin >> a;
        if(a>0)update(a,1);
        else{
            a=-a;
            int pos=0,canti=0;
            for(int i=LOG;i>=0;i--){
                if(pos+(1<<i)<=n && canti+BIT[pos+(1<<i)]<a){
                    canti+=BIT[pos+(1<<i)];
                    pos+=(1<<i);
                }
            }
            pos++;
            update(pos,-1);
        }
    }
    int pos=0,canti=0;
    for(int i=LOG;i>=0;i--){
        if(pos+(1<<i)<=n && canti+BIT[pos+(1<<i)]<1){
            canti+=BIT[pos+(1<<i)];
            pos+=(1<<i);
        }
    }
    pos++;
    if(pos==n+1)cout << 0;
    else cout << pos;
}