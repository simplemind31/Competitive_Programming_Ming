#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a,b;
vector<int> graph[100];
bool imposi[100][4];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie();
    freopen("revegetate.in","r",stdin);
    freopen("revegetate.out","w",stdout);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            if(imposi[i][j])continue;
            cout << j+1;
            for(auto u:graph[i])imposi[u][j]=true;
            break;
        }
    }
}