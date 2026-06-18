#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,res,maxi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    const int MOD=1000000007;
    const int A=uniform_int_distribution<int>(1,MOD-1)(rng);
    const int B=uniform_int_distribution<int>(1,MOD-1)(rng);
    const int C=uniform_int_distribution<int>(1,MOD-1)(rng);
    int powerA[10001],powerB[10001];
    powerA[0]=powerB[0]=1;
    for(int i=1;i<=10000;i++)powerA[i]=1ll*powerA[i-1]*A%MOD,powerB[i]=1ll*powerB[i-1]*B%MOD;
    cin >> n;
    vector<string> st(n);
    vector<ll> havalue(n);
    // eliminar los que son parte de otros
    for(int i=0;i<n;i++){
        cin >> st[i];
        int h1=0,h2=0;
        for(int j=0;j<st[i].size();j++){
            h1=(1ll*h1*A%MOD+st[i][j])%MOD;
            h2=(1ll*h2*B%MOD+st[i][j])%MOD;
        }
        havalue[i]=1ll*h1*C+h2;
    }
    for(int i=0;i<st.size();i++){
        bool xd=false;
        for(int j=0;j<st.size() && !xd;j++){
            if(i==j || st[i].size()>st[j].size())continue;
            // i es substring de j?
            int h1=0,h2=0;
            for(int l=0;l<st[i].size();l++){
                h1=(1ll*h1*A%MOD+st[j][l])%MOD;
                h2=(1ll*h2*B%MOD+st[j][l])%MOD;
            }
            if(1ll*h1*C+h2==havalue[i])xd=true;
            for(int l=st[i].size();l<st[j].size() && !xd;l++){
                h1=(1ll*h1*A%MOD+st[j][l])%MOD;
                h2=(1ll*h2*B%MOD+st[j][l])%MOD;
                h1=((h1-1ll*st[j][l-st[i].size()]*powerA[st[i].size()])%MOD+MOD)%MOD;
                h2=((h2-1ll*st[j][l-st[i].size()]*powerB[st[i].size()])%MOD+MOD)%MOD;
                if(1ll*h1*C+h2==havalue[i])xd=true;
            }
        }
        if(xd){
            st.erase(st.begin()+i);
            havalue.erase(havalue.begin()+i);
            i--;
        }
    }
    n=st.size();


    vector<ll> prefix[n],sufix[n];
    for(int i=0;i<n;i++){
        res+=st[i].size();
        int h1=0,h2=0;
        for(int j=0;j<st[i].size();j++){
            h1=(1ll*h1*A%MOD+st[i][j])%MOD;
            h2=(1ll*h2*B%MOD+st[i][j])%MOD;
            prefix[i].push_back(1ll*h1*C+h2);
        }
        h1=0,h2=0;
        for(int j=st[i].size()-1;j>=0;j--){
            h1=(h1+1ll*powerA[st[i].size()-1-j]*st[i][j]%MOD)%MOD;
            h2=(h2+1ll*powerB[st[i].size()-1-j]*st[i][j]%MOD)%MOD;
            sufix[i].push_back(1ll*h1*C+h2);
        }
        sort(ALL(sufix[i]));
    }
    int reduc[n][n];
    memset(reduc,0,sizeof(reduc));
    for(int i=0;i<n;i++){
        // j,i , el sufix de j con el prefix de i
        for(int j=0;j<n;j++){
            for(int l=st[i].size()-1;l>=0;l--){
                if(binary_search(ALL(sufix[j]),prefix[i][l])){
                    reduc[j][i]=l+1;
                    break;
                }
            }
        }
    }
    int perm[n];
    for(int i=0;i<n;i++)perm[i]=i;
    do{
        int now=0;
        for(int i=1;i<n;i++)now+=reduc[perm[i-1]][perm[i]];
        maxi=max(maxi,now);
    }while(next_permutation(perm,perm+n));
    cout << res-maxi;
}