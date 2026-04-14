#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
//const int raiz=448;
int n,m,q,a;
int grupos[5001][5001];
vector<bool> used;
int solve(int pos){
    int maxi=pos;
    for(int i=0;i<m;i++){
        if(grupos[i][pos] && !used[i]){
            used[i]=true;
            maxi=max(maxi,solve(pos+1));
            used[i]=false;
        }
    }
    return maxi;
}
// solve(pos,suma) 1e5 1e2 1e7
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector<pair<int,int>> nums(n);
    used.resize(n);
    for(int i=0;i<n;i++)cin >> nums[i].first;
    for(int i=0;i<n;i++){
        cin >> nums[i].second;
        grupos[--nums[i].second][nums[i].first]++;
    }
    // encontrar un camino de manera que no repite el mismo nodo
    cin >> q;
    while(q--){
        cin >> a;
        a--;
        grupos[nums[a].second][nums[a].first]--;
        int maxi=0;
        for(int i=0;i<m;i++){
            if(grupos[i][0]){
                used[i]=true;
                maxi=max(maxi,solve(1));
                used[i]=false;
            }
        }
        cout << maxi << '\n';
    }
}