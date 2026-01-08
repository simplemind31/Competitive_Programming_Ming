#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int t=1,n;
ll con[10],fact[1000001],ten[1000001];
string st;
ll bigmod(ll b,ll e){
    ll p=1;
    while(e){
        if(e&1){
            p*=b;
            p%=MOD;
        }
        e/=2;
        b*=b;
        b%=MOD;
    }
    return p;
}
ll inversemod(ll b){
    return bigmod(b,MOD-2);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    fact[0]=1;
    ten[0]=1;
    for(int i=1;i<=1000000;i++){
        fact[i]=(fact[i-1]*i)%MOD;
        ten[i]=(ten[i-1]*10)%MOD;
    }
    while(t--){
        cin >> st;
        n=st.size();
        for(int i=0;i<10;i++){
            con[i]=0;
        }
        for(int i=0;i<n;i++){
            con[st[i]-'0']++;
        }
        vector<pll> res(10);
        for(int i=0;i<10;i++){
            //si fixeo i
            if(con[i]==0){
                res[i]={0,0};
                continue;
            }
            con[i]--;
            ll temp1=0,temp2=0;
            temp1=(i*fact[n-1])%MOD;
            //temp1
            for(int j=0;j<10;j++){
                temp1*=inversemod(fact[con[j]]);
                temp1%=MOD;
            }
            for(int j=0;j<10;j++){
                //si fixeo j;
                if(con[j]==0)continue;
                con[j]--;
                ll nue=(j*fact[n-2])%MOD;
                for(int k=0;k<10;k++){
                    nue*=inversemod(fact[con[k]]);
                    nue%=MOD;
                }
                temp2+=nue;
                temp2%=MOD;
                con[j]++;
            }
            con[i]++;
            res[i]={temp1,temp2};
        }
        for(int i=0;i<n;i++){
            int dig=st[i]-'0';
            ll resp=0;
            resp=(res[dig].second*(((ten[n]-1)*inversemod(9))%MOD))%MOD;
            resp+=((res[dig].first-res[dig].second)*ten[n-i-1])%MOD;
            resp%=MOD;
            resp+=MOD;
            resp%=MOD;
            cout << resp << ' ';
        }
        cout << '\n';
    }
}