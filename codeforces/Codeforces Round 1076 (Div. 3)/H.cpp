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
bool impsum[200000],impval[200000];
int t,n,a,b;
vector<vector<int>> graph;
void dfs(int now,int ante){
    for(auto u:graph[now]){
        impsum[now]=(impsum[now]!=impval[u]);
    }
    for(auto u:graph[now]){
        if(u==ante)continue;
        dfs(u,now);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        graph.clear();
        cin >> n;
        graph.resize(n);
        for(int i=0;i<n;i++){
            impsum[i]=impval[i]=0;
            cin >> a;
            impval[i]=(a%2);
        }
        for(int i=1;i<n;i++){
            cin >> a >> b;
            graph[--a].push_back(--b);
            graph[b].push_back(a);
        }
        dfs(0,-1);
        vector<int> ord;
        set<int> nums[2][2];
        for(int i=0;i<n;i++){
            nums[impval[i]][impsum[i]].insert(i);
            //cout << i << ' ' << impval[i] << ' ' << impsum[i] << '\n';
        }
        // siempre quitar 0,1-> no hace nada luego 1,0 pero no se en que orden
        while(nums[0][0].size()+nums[0][1].size()+nums[1][0].size()+nums[1][1].size()){
            while(!nums[0][1].empty()){
                int top=*nums[0][1].begin();
                nums[0][1].erase(top);
                ord.push_back(top);
            }
            if(nums[1][0].size()){
                int top=*nums[1][0].begin();
                nums[1][0].erase(top);
                ord.push_back(top);
                for(auto u:graph[top]){
                    if(nums[impval[u]][impsum[u]].find(u)!=nums[impval[u]][impsum[u]].end()){
                        nums[impval[u]][impsum[u]].erase(u);
                        impsum[u]=!impsum[u];
                        nums[impval[u]][impsum[u]].insert(u);
                    }
                }
            }else{
                break;
            }
        }
        if(nums[0][0].size()+nums[0][1].size()+nums[1][0].size()+nums[1][1].size()){
            cout << "NO\n";
        }else{
            cout << "YES\n";
            for(auto u:ord){
                cout << u+1 << ' ';
            }
            cout << '\n';
        }
    }
}