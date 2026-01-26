#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend();
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int n,t=1,a,b,res;
int iz=-1;
bool xd;
vector<vector<int>> graph;
void dfs(int now,int ante){
    if(xd)return;
    if(iz==-1){
        iz=now;
    }else{
        cout << "? " <<  iz+1 << ' ' << now+1 << '\n';
        cout.flush();
        cin >> res;
        if(res==1){
            xd=true;
            cout << "? " <<  iz+1 << ' ' << iz+1 << '\n';
            cout.flush();
            cin >> res;
            if(res==1){
                cout << "! " << iz+1 << '\n';
                cout.flush();
            }else{
                cout << "! " << now+1 << '\n';
                cout.flush();
            }
            return;
        }
        iz=-1;
    }
    for(auto u:graph[now]){
        if(u==ante)continue;
        dfs(u,now);
        if(xd)return;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        xd=false;
        iz=-1;
        cin >> n;
        graph.clear();
        graph.resize(n);
        for(int i=1;i<n;i++){
            cin >> a >> b;
            graph[--a].push_back(--b);
            graph[b].push_back(a);
        }
        dfs(0,-1);
        if(!xd){
            cout << "! " << iz+1 << '\n';
            cout.flush();
        }
    }
}