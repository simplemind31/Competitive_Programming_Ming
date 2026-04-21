#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
char a;
map<vector<bool>,double> dp;
vector<bool> nada(100);
bool mat[100][100];
double solve(vector<bool>& estado){
    if(estado==nada)return 0;
    if(dp.count(estado))return dp[estado];
    int tot=0;
    for(int i=0;i<n;i++)if(estado[i])tot++;
    double now=0;
    for(int i=0;i<n;i++){
        if(estado[i]){
            vector<int> posi;
            estado[i]=0;
            posi.push_back(i);
            for(int j=0;j<n;j++){
                if(mat[i][j] && estado[j]){
                    estado[j]=0;
                    posi.push_back(j);
                }
            }
            now+=1.0/tot*(solve(estado)+1);
            for(auto u:posi)estado[u]=1;
        }
    }
    dp[estado]=now;
    return now;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a;
            mat[i][j]=(a=='1');
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)mat[i][j]=mat[i][j]||(mat[i][k]&&mat[k][j]);
        }
    }
    vector<bool> todo(100,1);
    cout << fixed << setprecision(12) << solve(todo);
}