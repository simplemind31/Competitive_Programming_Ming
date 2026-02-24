#include "light.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll con;
void prepare(){
	con=1;
}
pair<ll,vector<ll>> join(ll p){
	con+=p;
	vector<ll> res;
	for(int i=0;(1<<i)<con;i++){
		res.push_back(con-((1ll<<i)-1));
	}
	return make_pair(p,res);
}
pair<ll,vector<ll>> leave(ll p){
	xd=true;
	return make_pair(0,nada);
}
