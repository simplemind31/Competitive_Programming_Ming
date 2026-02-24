#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;
const int MAXN=2000000;
int n,k,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    int can0=0,pos=0;
    vector<int> deg(n,k),dist[n];
    for(int i=0;i<n;i++){
        cin >> a;
        dist[a].push_back(i);
    }
    if(dist[0].size()!=1){
        cout << -1;
        return 0;
    }
    vector<pair<int,int>> res;
    for(int i=0;i<n-1;i++){
        int j=0,l=0,con=0;
        while(j<dist[i].size() && l<dist[i+1].size()){
            if(deg[dist[i][j]]==0){
                j++;
                continue;
            }
            res.push_back({dist[i][j],dist[i+1][l]});
            deg[dist[i][j]]--;
            deg[dist[i+1][l]]--;
            l++;
            con++;
            if(con==k){
                con=0;
                j++;
            }
        }
        if(l<dist[i+1].size()){
            cout << -1;
            return 0;
        }
    }
    cout << res.size() << '\n';
    for(auto u:res)cout << u.first+1 << ' ' << u.second+1 << '\n';
}