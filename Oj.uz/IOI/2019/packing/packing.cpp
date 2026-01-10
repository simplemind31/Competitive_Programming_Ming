#include <bits/stdc++.h>
using namespace std;
int n,k,a,now;
vector<vector<int>> posi;
const int cantidadposi=2428;
vector<int> con[cantidadposi],posiciones[10];
vector<int> res;
void solve(int x,int suma,int target){
    suma+=x;
    res.push_back(x);
    if(suma==target){
        posi.push_back(res);
        res.pop_back();
        return;
    }
    for(int i=min(x,target-suma);i>0;i--){
        solve(i,suma,target);
    }
    res.pop_back();
    return;
}
bool cmp(vector<int> un,vector<int> dos){
    if(un[1]==dos[1]){
        if(un[0]==dos[0]){
            for(int i=2;i<min(un.size(),dos.size());i++){
                if(un[i]!=dos[i]){
                    return un[i]>dos[i];
                }
            }
        }
        return un[0]>dos[0];
    }
    return un[1]>dos[1];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int j=20;j>=1;j--){
        for(int i=min(10,j);i>0;i--){
            res.push_back(j);
            solve(i,0,j);
            res.pop_back();
        }
    }
    sort(posi.begin(),posi.end(),cmp);
    for(int i=0;i<cantidadposi;i++){
        con[i].resize(10);
        for(int j=1;j<posi[i].size();j++){
            con[i][posi[i][j]-1]++;
        }
    }
    cin >> n >> k;
    res.resize(n);
    for(int i=0;i<n;i++){
        cin >> a;
        posiciones[a-1].push_back(i);
    }
    bool lol=true;
    while(lol){
        for(int i=0;i<cantidadposi;i++){
            int xd=true;
            for(int j=0;j<10;j++){
                if(con[i][j]>posiciones[j].size()){
                    xd=false;
                    break;
                }
            }
            if(!xd)continue;
            for(int j=0;j<10;j++){
                for(int l=0;l<con[i][j];l++){
                    res[posiciones[j].back()]=now;
                    posiciones[j].pop_back();
                }
            }
            break;
        }
        lol=false;
        now++;
        for(int i=0;i<10;i++){
            if(posiciones[i].size()>0){
                lol=true;
                break;
            }
        }
    }
    cout << now << '\n';
    for(int i=0;i<n;i++){
        cout << res[i] << ' ';
    }
}