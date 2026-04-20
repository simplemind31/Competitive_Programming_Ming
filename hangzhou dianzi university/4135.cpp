#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
typedef long long ll;
ll n,t,a,b;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    for(int caso=1;caso<=t;caso++){
        cin >> a >> b >> n;
        vector<ll> div;
        for(ll i=2;i*i<=n;i++){
            if(n%i==0){
                div.push_back(i);
                while(n%i==0)n/=i;
            }
        }
        if(n>1)div.push_back(n);
        int tam=div.size();
        ll res1=0,res2=0;
        for(int i=0;i<(1<<tam);i++){
            ll mcm=1,con=0;
            for(int j=0;j<tam;j++){
                if(i&(1<<j)){
                    mcm=mcm*div[j]/gcd(mcm,div[j]);
                    con++;
                }
            }
            if(mcm==1)continue;
            if(con&1){
                res1+=b/mcm;
                res2+=(a-1)/mcm;
            }else{
                res1-=b/mcm;
                res2-=(a-1)/mcm;
            }
        }
        cout << "Case #" << caso << ": " << b-a+1-(res1-res2) << '\n';
    }
}