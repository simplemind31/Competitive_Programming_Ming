#include <bits/stdc++.h>
#include "shoes.h"
#define lsOne(x) (x)&-(x)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
vi fenwick(2e5+1);
void update(int a,int b){
	while(a<=2e5+1){
		fenwick[a]+=b;
		a+=lsOne(a);
	}
}
int sum(int a){
	int suma=0;
	while(a>0){
		suma+=fenwick[a];
		a-=lsOne(a);
	}
	return suma;
}
int ran(int a,int b){
	return sum(b)-sum(a-1);
}
long long count_swaps(std::vector<int> s) {
	ll res=0;
	int n=s.size();
	s.push_back(0);
	stack<int> lastposi[n+1];
	stack<int> lastnega[n+1];
	for(int i=n;i>0;i--){
		s[i]=s[i-1];
		if(s[i]<0){
			lastnega[-s[i]].push(i);
		}else{
			lastposi[s[i]].push(i);
		}
	}
	s[0]=0;
	for(int i=1;i<=n;i++){
		ll temp=0;
		int x;
		if(s[i]==0){
            //cout << "x "; 
			continue;
		}
		if(s[i]<0){
			x=lastposi[-s[i]].top();
			temp+=ran(i,x);
            temp+=x-i-1;
            //cout << temp << " ";
			update(i,1);
			update(x,-1);
		}else{
			x=lastnega[s[i]].top();
			temp+=ran(i,x);
			update(i,1);
			update(x,-1);
			temp+=x-i;
            //cout << temp << " ";
		}
		s[x]=0;
		lastposi[abs(s[i])].pop();
		lastnega[abs(s[i])].pop();
        s[i]=0;
		res+=temp;
	}
	return res;
}