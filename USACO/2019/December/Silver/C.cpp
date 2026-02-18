#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,a,b;
char c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("milkvisits.in","r",stdin);
    freopen("milkvisits.out","w",stdout);
    cin >> n >> q;
    bool tip[n];
    int pad[n];
    vector<int> graph[n];
    for(int i=0;i<n;i++){
        cin >> c;
        tip[pad[i]=i]=c=='H';
    }
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        if(pad[i]!=i)continue;
        queue<int> bfs;
        bfs.push(i);
        while(!bfs.empty()){
            int top=bfs.front();
            bfs.pop();
            for(auto u:graph[top]){
                if(tip[u]==tip[i] && pad[u]!=i){
                    pad[u]=i;
                    bfs.push(u);
                }
            }
        }
    }
    while(q--){
        cin >> a >> b >> c;
        if(pad[--a]==pad[--b] && tip[a]==(c!='H'))cout << 0;
        else cout << 1;
    }
}