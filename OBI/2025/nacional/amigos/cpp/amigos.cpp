#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
vll a1,b1,a2,b2;
vector<pll> tot1,tot2;
ll n1,n2;
void solve1(ll pos,ll suma1,ll suma2){
	if(pos==n1){
		tot1.push_back({suma1,suma2});
		return;
	}
	solve1(pos+1,suma1+a1[pos],suma2);
	solve1(pos+1,suma1,suma2+b1[pos]);
}
	void solve2(ll pos,ll suma1,ll suma2){
		if(pos==n2){
			tot2.push_back({suma1,suma2});
			return;
		}
		solve2(pos+1,suma1+a2[pos],suma2);
		solve2(pos+1,suma1,suma2+b2[pos]);
	}
vector<long long> best_k(int N, int K, vector<long long> A, vector<long long> B){
  if(N<=20){
    a1=A,b1=B;
    n1=N;
    solve1(0,0,0);
    vll res(tot1.size());
    for(int i=0;i<tot1.size();i++){
      res[i]=abs(tot1[i].first-tot1[i].second);
    }
    sort(ALL(res));
    while(res.size()>K){
      res.pop_back();
    }
    return res;
  }
  n1=(N+1)/2;
  n2=N-n1;
  for(int i=0;i<n1;i++){
	a1.push_back(A[i]);
	b1.push_back(B[i]);
  }
  for(int i=n1;i<N;i++){
	a2.push_back(A[i]);
	b2.push_back(B[i]);
  }
  solve1(0,0,0);
  solve2(0,0,0);
  ll mini=1e18;
  if(tot2.empty()){
	  for(int i=0;i<tot1.size();i++){
		  mini=min(mini,abs(tot1[i].first-tot1[i].second));
	  }
	  return {mini};
  }
  vll parte1,parte2posi,parte2nega;
  for(int i=0;i<tot2.size();i++){
	  ll temp=tot2[i].first-tot2[i].second;
	if(temp>=0){
		parte2posi.push_back(temp);
	}else{
		parte2nega.push_back(-temp);
	}
  }
  sort(ALL(parte2posi));
  sort(ALL(parte2nega));
  for(int i=0;i<tot1.size();i++){
	ll temp=tot1[i].first-tot1[i].second;
	if(temp>=0){
		//buscar mini posi,
		if(!parte2posi.empty()){
			mini=min(mini,abs(temp+parte2posi[0]));
		}
		//buscar temp
		int x=upper_bound(ALL(parte2nega),temp)-parte2nega.begin();
		if(x<parte2nega.size()){
			mini=min(mini,abs(temp-parte2nega[x]));
		}
		x--;
		if(x>=0){
			mini=min(mini,abs(temp-parte2nega[x]));
		}
	}else{
		//buscar mini nega;
		if(!parte2nega.empty()){
			mini=min(mini,abs(temp-parte2nega[0]));
		}
		//buscar
		temp=-temp;
		int x=upper_bound(ALL(parte2posi),temp)-parte2posi.begin();
		if(x<parte2posi.size()){
			mini=min(mini,abs(-temp+parte2posi[x]));
		}
		x--;
		if(x>=0){
			mini=min(mini,abs(-temp+parte2posi[x]));
		}
	}
  }
  return {mini};
}
