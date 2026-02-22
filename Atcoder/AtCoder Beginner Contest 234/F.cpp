#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
ll n,con[26],res[5001],combi[5001][5001],fina;
// hay res[i] cantidad de posi con longitud i
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<=5000;i++){
        combi[i][0]=combi[i][i]=1;
        for(int j=1;j<i;j++){
            combi[i][j]=(combi[i-1][j]+combi[i-1][j-1])%MOD;
        }
    }
    cin >> st;
    for(auto u:st)con[u-'a']++;
    res[0]++;
    for(int i=0;i<26;i++){
        for(int j=5000;j>=0;j--){
            for(int k=1;k<=con[i] && j+k<=5000;k++){
                res[j+k]=(res[j+k]+combi[k+j][k]*res[j])%MOD;
            }
        }
        //cout << res[0] << ' ' << res[1] << ' ' << res[2] << ' ' << res[3] << ' ' << res[4] << '\n';
    }
    for(int i=1;i<=5000;i++)fina=(fina+res[i])%MOD;
    cout << fina;
}