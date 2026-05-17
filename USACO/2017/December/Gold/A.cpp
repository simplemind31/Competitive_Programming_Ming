#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
int n,d;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("piepie.in","r",stdin);
    freopen("piepie.out","w",stdout);
    queue<pair<int,bool>> bfs;
    cin >> n >> d;
    vector<vector<int>> rescow(n,vector<int>(2,1e9));
    vector<vector<pair<int,int>>> cow(n,vector<pair<int,int>>(2));
    set<pair<int,int>> ord[2];
    for(int i=0;i<n;i++){
        cin >> cow[i][0].first >> cow[i][0].second;
        ord[0].insert({cow[i][0].second,i});
        if(cow[i][0].second==0){
            rescow[i][0]=1;
            bfs.push({i,0});
            ord[0].erase({cow[i][0].second,i});
        }
    }
    for(int i=0;i<n;i++){
        cin >> cow[i][1].second >> cow[i][1].first;
        ord[1].insert({cow[i][1].second,i});
        if(cow[i][1].second==0){
            rescow[i][1]=1;
            bfs.push({i,1});
            ord[1].erase({cow[i][1].second,i});
        }
    }

    while(!bfs.empty()){
        pair<int,bool> top=bfs.front();
        bfs.pop();
        int val=cow[top.first][top.second].first;
        // tengo que encontrar uno que tiene [val-d,val] del cow[!top.second].first
        auto p=ord[!top.second].lower_bound({val-d,-1e9});
        while(p!=ord[!top.second].end() && p->first<=val){
            auto ne=next(p);
            rescow[p->second][!top.second]=rescow[top.first][top.second]+1;
            bfs.push({p->second,!top.second});
            ord[!top.second].erase(p);
            p=ne;
        }
    }
    for(int i=0;i<n;i++){
        if(rescow[i][0]==1e9)rescow[i][0]=-1;
        cout << rescow[i][0] << '\n';
    }
}