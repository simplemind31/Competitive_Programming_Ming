#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
bool visited[1000];
char c;
int n,a,b,m,res[1000];
vector<vector<int>> E,N;
vector<int> graph[1000];
int dfs(int now){
    if(visited[now])return res[now];
    visited[now]=true;
    for(auto u:graph[now]){
        res[now]+=1+dfs(u);
    }
    return res[now];
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> c >> a >> b;
        if(c=='E')E.push_back({b,a,i});
        else N.push_back({a,b,i});
    }
    sort(ALL(E));
    sort(ALL(N));
    n=E.size();
    m=N.size();
    //vector<int> tapadoE(n,-1),tapadoN(m,-1);
    vector<int> tapado(n+m,-1),tapadoreal(n+m,-1);
    for(int i=0;i<n;i++)swap(E[i][0],E[i][1]);
    for(int i=0;i<n;i++){
        // procesar E;
        for(int j=0;j<m;j++){
            if(E[i][0]>N[j][0] || E[i][1]<N[j][1] || tapado[N[j][2]]!=-1)continue;
            if(N[j][0]-E[i][0]<E[i][1]-N[j][1]){
                //E llego primero
                tapado[N[j][2]]=E[i][2];
            }else if(N[j][0]-E[i][0]>E[i][1]-N[j][1]){
                //N llego primero
                tapado[E[i][2]]=N[j][2];
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        tapadoreal[E[i][2]]=tapado[E[i][2]];
    }
    /*for(int i=0;i<m;i++){
        tapadoreal[N[i][2]]=tapado[N[i][2]];
    }*/
    tapado.assign(n+m,-1);
    for(int i=0;i<m;i++){
        // procesar N;
        for(int j=0;j<n;j++){
            if(E[j][0]>N[i][0] || E[j][1]<N[i][1] || tapado[E[j][2]]!=-1)continue;
            if(tapado[N[i][2]]==E[j][2])continue;
            if(E[j][1]-N[i][1]<N[i][0]-E[j][0]){
                //pass;
                tapado[E[j][2]]=N[i][2];
            }else if(E[j][1]-N[i][1]>N[i][0]-E[j][0]){
                tapado[N[i][2]]=E[j][2];
                break;
            }
        }
    }
    for(int i=0;i<m;i++){
        tapadoreal[N[i][2]]=tapado[N[i][2]];
    }
    for(int i=0;i<n;i++){
        if(tapadoreal[E[i][2]]!=-1)graph[tapadoreal[E[i][2]]].push_back(E[i][2]);
    }
    for(int i=0;i<m;i++){
        if(tapadoreal[N[i][2]]!=-1)graph[tapadoreal[N[i][2]]].push_back(N[i][2]);
    }
    for(int i=0;i<n+m;i++){
        cout << dfs(i) << '\n';
    }
}