#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int t,q,c,x;
ll bigmod(ll b,ll e){
    ll p=1;
    while(e){
        if(e&1){
            p=(p*b)%MOD;
        }
        e/=2;
        b=(b*b)%MOD;
    }
    return p;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    ll pow2[200001];
    pow2[0]=1;
    for(int i=1;i<=2e5;i++){
        pow2[i]=(2*pow2[i-1])%MOD;
    }
    while(t--){
        cin >> q;
        int con=0;
        vector<int> cade,res(q+1,-1);
        res[0]=0;
        for(int i=0;i<q;i++){
            cin >> c >> x;
            if(cade.empty()){
                con=1;
                res[con]=c;
            }else if(cade.back()==c){
                con++;
                if(res[con]==-1){
                    res[con]=c;
                }
            }else{
                con=1;
            }
            cade.push_back(c);
            if(x<=q && res[x]!=-1){
                cout << res[x] << '\n';
            }else{
                if(cade.back()){
                    ll resp=(pow2[x]-pow2[x-con]+MOD)%MOD;
                    resp*=bigmod(pow2[x]-1,MOD-2);
                    resp%=MOD;
                    cout << resp << '\n';
                }else{
                    ll resp=pow2[x-c]-1;
                    resp*=bigmod(pow2[x]-1,MOD-2);
                    resp%=MOD;
                    cout << resp << '\n';
                }
            }
        }
    }
}