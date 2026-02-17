#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b,c,q,len[300000],pad[300000][20];
vector<int> graph[300000];
void dfs(int node,int ante){
    for(auto u:graph[node]){
        if(u==ante)continue;
        pad[u][0]=node;
        len[u]=len[node]+1;
        dfs(u,node);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,-1);
    for(int j=1;j<20;j++){
        for(int i=0;i<n;i++){
            pad[i][j]=pad[pad[i][j-1]][j-1];
        }
    }
    cin >> q;
    while(q--){
        cin >> a >> b >> c;
        a--;b--;
        int origa=a,origb=b;
        for(int i=19;i>=0;i--){
            if(len[a]>len[b]){
                if((len[a]-len[b])&(1<<i))a=pad[a][i];
            }else{
                if((len[b]-len[a])&(1<<i))b=pad[b][i];
            }
        }
        if(a!=b){
            for(int i=19;i>=0;i--){
                if(pad[a][i]!=pad[b][i]){
                    a=pad[a][i];
                    b=pad[b][i];
                }
            }
            a=pad[a][0];

        }
        //origa->a->orgib
        if(len[origa]-len[a]>c){
            //está c arriba de a
            //cout << "b";
            int dist=c;
            a=origa;
            for(int i=19;i>=0;i--){
                if(dist&(1<<i))a=pad[a][i];
            }
            cout << a+1 << '\n';
        }else{
            if(len[origa]-len[a]+len[origb]-len[a]>c){
                int dist=len[origb]-len[a]-(c-(len[origa]-len[a]));
                // esta de  para arriba de c
                //cout << "a";
                b=origb;
                for(int i=19;i>=0;i--){
                    if(dist&(1<<i))b=pad[b][i];
                }
                cout << b+1 << '\n';
            }else{
                //cout << "c";
                cout << origb+1 << '\n';
            }
        }
    }
}