#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n,a;
int sparse[64][50][50],res; 
ll x;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> x;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a;
            if(a)sparse[0][i][j]=1;
        }
    }
    for(int i=1;i<64;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                for(int l=0;l<n;l++){
                    sparse[i][j][l]=(sparse[i][j][l]+1ll*sparse[i-1][j][k]*sparse[i-1][k][l]%MOD)%MOD;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        vector<int> ahora(n);
        ahora[i]=1;
        for(int j=63;j>=0;j--){
            if(x&(1ll<<j)){
                vector<int> nue(n);
                for(int k=0;k<n;k++){
                    for(int l=0;l<n;l++){
                        nue[l]=(nue[l]+1ll*ahora[k]*sparse[j][k][l]%MOD)%MOD;
                    }
                }
                ahora=nue;
            }
        }
        for(auto u:ahora){
            res=(res+u)%MOD;
        }
    }
    cout << res;
}