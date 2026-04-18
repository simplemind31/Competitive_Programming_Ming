#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll a,b;
ll bigmod(ll b,ll e){
    ll p=1;
    while(e){
        if(e&1)p*=b;
        b*=b;
        e>>=1;
    }
    return p;
}
ll solve(string x){
    if(x.size()==1){
        return x[0]-'0'+1;
    }
    int n=x.size();
    // todos numeros con menores digitos que x
    ll res=0;
    for(int i=1;i<n;i++){
        // si tiene i digitos;
        // la primera hay 9 opciones, la segunda hay 9 opciones, luego hay 8 opciones
        if(i==1){
            res+=9;
            continue;
        }
        res+=9*9*bigmod(8,i-2);
    }
    //cout << res << ' ';
    res+=(x[0]-'0'-1)*9*bigmod(8,n-2);
    //cout << res << '\n';
    // 0 esta fijado
    bool xd=true;
    for(int i=1;i<n && xd;i++){
        // si eligo uno menor que x[i]
        if(i==1){
            // elegir los menores
            for(int j=0;j<x[i]-'0';j++){
                if(j==x[i-1]-'0')continue;
                res+=bigmod(8,n-i-1);
            }
            if(x[i]==x[i-1])xd=false;
        }else{
            for(int j=0;j<x[i]-'0';j++){
                if(j==x[i-1]-'0' || j==x[i-2]-'0')continue;
                res+=bigmod(8,n-i-1);
            }
            if(x[i]==x[i-1] || x[i]==x[i-2])xd=false;
        }
    }
    res++;//0
    if(xd)res++;
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> b;
    if(b-a<=100000){
        ll con=0;
        for(ll i=a;i<=b;i++){
            ll x=i;
            ll ante=-1,subante=-1;
            bool xd=true;
            while(x && xd){
                if(x%10==ante ||x%10==subante)xd=false;
                subante=ante;
                ante=x%10;
                x/=10;
            }
            if(xd)con++;
        }
        cout << con;
        return 0;
    }
    //solve(to_string(a));
    cout << solve(to_string(b))-solve(to_string(a-1));
}