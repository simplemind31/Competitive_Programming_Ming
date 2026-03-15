#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
class Fancy {
public:
    int a,b;
    vector<int> v;
    int bigmod(int b,int e){
        int p=1;
        while(e){
            if(e&1)p=1ll*p*b%MOD;
            b=1ll*b*b%MOD;
            e>>=1;
        }
        return p;
    }
    int inverse(int b){return bigmod(b,MOD-2);}
    Fancy(){
        a=1;
        b=0;
    }
    void append(int val){v.push_back(1ll*(val-b+MOD)%MOD*inverse(a)%MOD);}
    void addAll(int inc){b=(b+inc)%MOD;}
    void multAll(int m) {
        a=1ll*a*m%MOD;
        b=1ll*b*m%MOD;
    }
    int getIndex(int idx){
        if(idx>=v.size())return -1;
        return (1ll*a*v[idx]+b)%MOD;
    }
};