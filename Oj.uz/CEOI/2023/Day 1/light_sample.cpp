#include "light.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll con;
bool xd;
void prepare(){
	con=1;
	xd=false;
}
pair<ll,vector<ll>> join(ll p){
	con+=p;
	vector<ll> res;
	if(xd){
		res={con};
		return make_pair(p,res);
	}
	for(int i=0;(1ll<<i)<con;i++){
		res.push_back(con-((1ll<<i)-1));
	}
	if(res.back()!=1)res.push_back(1);
	reverse(res.begin(),res.end());
	return make_pair(p,res);
}
pair<ll,vector<ll>> leave(ll p){
	xd=true;
	con-=p;
	vector<ll> res;
	if(con==1)res={1};
	else res={1,con};
	return make_pair(p,res);
}
