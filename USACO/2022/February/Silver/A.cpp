#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,priori[500][500],res[500],libre,ord[500][500];
bitset<500> visited;
bool dfs(int node){
    // cambiar por cualquier que sea mejor;
    visited[node]=true;
    if(priori[node][libre]<priori[node][node])return true;
    for(int i=0;i<n;i++){
        if(ord[node][i]==node)return false;
        if(visited[ord[node][i]])continue;
        if(priori[node][ord[node][i]]<priori[node][node]){
            if(dfs(ord[node][i]))return true;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> ord[i][j];
            priori[i][--ord[i][j]]=j;
        }
        res[i]=i;
    }
    for(int i=0;i<n;i++){
        // cambiar i con uno mejor;
        for(int j=0;j<n;j++){
            if(ord[i][j]==i)break;
            visited=0;
            // puedo cambiar res[i] con ord[i][j]?
            // tengo que pedir al j;
            libre=i;
            // hasta que acepten i
            // now cambia con cualquier mejor, o si acepta el libre
            visited[i]=true;
            if(dfs(ord[i][j])){
                res[i]=ord[i][j];
                break;
            }
        }
    }
    for(int i=0;i<n;i++)cout << res[i]+1 << '\n';
}