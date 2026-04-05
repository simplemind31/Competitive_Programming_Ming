#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
bool imposi[52][52];
vector<vector<int>> identidad;
int m,k;
ll n;
string st;
// empiezan en i terminan en j;
vector<vector<int>> combi(vector<vector<int>> a,vector<vector<int>> b){
    vector<vector<int>> res(m,vector<int>(m));
    for(int i=0;i<m;i++){
        for(int ii=0;ii<m;ii++){
            if(a[i][ii]==0)continue;
            for(int jj=0;jj<m;jj++){
                if(imposi[ii][jj])continue;
                for(int j=0;j<m;j++){
                    if(b[jj][j]==0)continue;
                    res[i][j]=(res[i][j]+1ll*a[i][ii]*b[jj][j]%MOD)%MOD;
                }
            }
        }
    }
    return res;
}
int c(char c){return (c>='a')?c-'a':26+c-'A';}
void exp(vector<vector<int>>& b,ll e){
    if(e==1)return;
    exp(b,e>>1);
    b=combi(b,b);
    if(e&1)b=combi(identidad,b);
    return;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    while(k--){
        cin >> st;
        imposi[c(st[0])][c(st[1])]=1;
    }
    identidad.assign(m,vector<int>(m));
    for(int i=0;i<m;i++)identidad[i][i]=1;
    vector<vector<int>> b=identidad;
    exp(b,n);
    int res=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            res=(res+b[i][j])%MOD;
        }
    }
    cout << res;
}