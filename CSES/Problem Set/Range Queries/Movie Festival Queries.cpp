#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,tiempo[1000002],a,b,mini=1e6+1,res[1000002][20];
vector<int> posi[1000002];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    while(n--){
        cin >> a >> b;
        tiempo[b]=max(tiempo[b],a);
    }
    posi[1000000].push_back(1e6+1);
    res[1000001][0]=1000001;
    for(int i=1e6;i>=0;i--){
        // todos los posi[i] están habilitados
        for(auto u:posi[i])mini=min(mini,u);
        res[i][0]=mini;
        posi[tiempo[i]].push_back(i);
    }
    for(int j=1;j<20;j++){
        for(int i=1;i<=1e6+1;i++){
            res[i][j]=res[res[i][j-1]][j-1];
        }
    }
    while(q--){
        cin >> a >> b;
        int resp=0;
        for(int j=19;j>=0;j--){
            if(res[a][j]>b)continue;
            resp+=1<<j;
            a=res[a][j];
        }
        cout << resp << '\n';
    }
}