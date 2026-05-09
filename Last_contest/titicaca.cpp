//#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <array>
#include <queue>
#include <stack>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,A,B,a,b,c;
vector<pair<int,int>> points;
vector<vector<int>> graph;
/*
Hola Diego estoy seguro que e problema  tiene que ver con:
NO EXISTEN INTERSECCIONES
pero no tenog idea xd
*/
vector<int> ini,fin;
vector<bool> visited;
void dfs(int node){
    visited[node]=true;
    for(auto u:graph[node]){
        if(!visited[u])dfs(u);
    }
}
bool cmp(int a,int b){return points[a].second>points[b].second;}
int main(){
	cin >> n >> m >> A >> B;
    graph.resize(n);
    points.resize(n);
    for(int i=0;i<n;i++){
        cin >> points[i].first >> points[i].second;
        if(points[i].first==0)ini.push_back(i);
        else if(points[i].first==A)fin.push_back(i);
    }
    while(m--){
        cin >> a >> b >> c;
        graph[--a].push_back(--b);
        if(c==2)graph[b].push_back(a);
    }
    sort(ALL(ini),cmp);
    for(auto u:ini){
        visited.assign(n,false);
        visited[u]=true;
        dfs(u);
        int res=0;
        for(auto v:fin)res+=visited[v];
        cout << res << '\n';
    }
}
