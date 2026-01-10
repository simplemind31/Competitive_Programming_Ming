#include "wiring.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll min_total_length(vector<int> r, vector<int> b){
	vector<pair<int,int>> nue;
	ll suma=0;
	int i=0,j=0,n=r.size(),m=b.size();
	while(i<n && j<m){
		if(r[i]<b[j])nue.push_back({0,r[i++]});
		else nue.push_back({1,b[j++]});
	}
	while(i<n)nue.push_back({0,r[i++]});
	while(j<m)nue.push_back({1,b[j++]});
	vector<bool> usado(n+m);
	for(int i=1;i<n+m;i++){
		if(nue)
	}
	return suma;
}
//0012100120121200000022120102121021220022120
//122200000012102011