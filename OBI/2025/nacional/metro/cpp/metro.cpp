#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int dsu[300005];
vector<pair<int,int>> graph[300005];
int find(int x){
	if(x==dsu[x]){
		return x;
	}
	return dsu[x]=find(dsu[x]);
}
bool unir(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y){
		return false;
	}
	dsu[x]=y;
	return true;
}
vector<int> orden_lineas_metro(int N, int M, vector<tuple<int, int, int>> lineas){
	for(int i=0;i<N;i++){
		dsu[i]=i;
	}
	vector<int> valor(M);
	vector<vector<int>> edges(M);
	for(int i=0;i<M;i++){
		int a=get<0>(lineas[i]);
		int b=get<1>(lineas[i]);
		int c=get<2>(lineas[i]);
		edges[i]={a-1,b-1,c};
		swap(edges[i][0],edges[i][2]);
	}
	sort(ALL(edges));
	for(int i=0;i<M;i++){
		valor[i]=edges[i][0];
		edges[i][0]=i;
		graph[edges[i][1]].push_back({edges[i][0],edges[i][2]});
		graph[edges[i][2]].push_back({edges[i][0],edges[i][1]});
	}
	vector<bool> usado(M,false);
	vector<vector<int>> MST;
	priority_queue<int> ayuda;
	for(int i=0;i<M;i++){
		if(unir(edges[i][1],edges[i][2])){
			MST.push_back(edges[i]);
		}
	}
	reverse(ALL(MST));
	for(int i=0;i<N;i++){
		dsu[i]=i;
	}
	vector<int> orden;
	for(int i=0;i<MST.size();i++){
		while(!ayuda.empty()){
			if(ayuda.top()>MST[i][0]){
				orden.push_back(ayuda.top());
				ayuda.pop();
			}else{
				break;
			}
		}
		orden.push_back(MST[i][0]);
		usado[MST[i][0]]=true;
		int cabex=find(MST[i][1]);
		int cabey=find(MST[i][2]);
		if(graph[cabex].size()>graph[cabey].size()){
			swap(cabex,cabey);
		}
		for(auto u:graph[cabex]){
			if(usado[u.first]){
				continue;
			}
			u.second=find(u.second);
			if(u.second==cabey){
				usado[u.first]=true;
				ayuda.push(u.first);
				graph[cabey].push_back(u);
			}else if(u.second==cabex){
				continue;
			}else{
				graph[cabey].push_back(u);
			}
		}
		dsu[cabex]=cabey;
		graph[cabex].clear();
	}
	while(!ayuda.empty()){
		orden.push_back(ayuda.top());
		ayuda.pop();
	}
	for(int i=0;i<M;i++){
		orden[i]=valor[orden[i]];
	}
	return orden;
}
