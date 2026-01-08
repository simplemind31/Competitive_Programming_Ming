//task3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int n;
vector<int> muro;
vector<vector<int>> st;
//maxima cantidad de 2 segudos, cantidad de 2 a la iz, cantidad a la derecha;
void build(int node,int l,int r){
	if(l==r){
		if(muro[l]==2){
			st[node]={1,1,1};
		}else{
			st[node]={0,0,0};
		}
		return;
	}
	int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
	build(hiji,l,mid);
	build(hijd,mid+1,r);
	int a=max({st[hiji][0],st[hijd][0],st[hiji][2]+st[hijd][1]});
	int b=st[hiji][1],c=st[hijd][2];
	if(b==mid-l+1){
		b+=st[hijd][1];
	}
	if(c==r-mid){
		c+=st[hiji][2];
	}
	st[node]={a,b,c};
}
vector<int> query(int node,int l,int r,int i,int j){
	if(r<i || j<l){
		return {0,0,0};
	}
	if(i<=l && r<=j){
		return st[node];
	}
	int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
	if(i>mid){
		//solo check derecha
		return query(hijd,mid+1,r,i,j);
	}else if(j<=mid){
		//solo check iz
		return query(hiji,l,mid,i,j);
	}else{
		vector<int> temp1=query(hiji,l,mid,i,j),temp2=query(hijd,mid+1,r,i,j);
		int a=max({temp1[0],temp2[0],temp1[2]+temp2[1]});
		int b=st[hiji][1],c=st[hijd][2];
		if(b==mid-l+1){
			b+=temp2[1];
		}
		if(c==r-mid){
			c+=temp1[2];
		}
		return {a,b,c};
	}
}
vector<int> altura_maxima(int N,vector<int> columnas,int Q,vector<tuple<int,int,int>> ataques){
	n=N;
	muro=columnas;
	st.resize(4*n+5);
	build(0,0,n-1);
	vector<int> res;
	for(int i=0;i<Q;i++){
		int l=get<0>(ataques[i]);
		int r=get<1>(ataques[i]);
		int w=get<2>(ataques[i]);
		l--;
		r--;
		int a=query(0,0,n-1,l,r)[0];
		if(a>=w){
			res.push_back(2);
		}else{
			res.push_back(1);
		}
	}
	return res;
}

/*#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int n;
vector<int> st,muro;
void build(int node,int l,int r){
	if(l==r){
		st[node]=muro[l];
		return;
	}
	int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
	build(hiji,l,mid);
	build(hijd,mid+1,r);
	st[node]=min(st[hiji],st[hijd]);
}
int query(int node,int l,int r,int i,int j){
	if(r<i || j<l){
		return 1e9;
	}
	if(i<=l && r<=j){
		return st[node];
	}
	int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
	return min(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
}
vector<int> altura_maxima(int N,vector<int> columnas,int Q,vector<tuple<int,int,int>> ataques){
	n=N;
	muro=columnas;
	st.resize(4*n+5);
	build(0,0,n-1);
	vector<int> res;
    //task 1
    for(int i=0;i<Q;i++){
		int l=get<0>(ataques[i]);
		int r=get<1>(ataques[i]);
		int w=get<2>(ataques[i]);
		l--;
		r--;
        //task1
		//int temp=muro[r-w+1];
		//res.push_back(temp);
        //task 2 y 4
        //int maxi=0;
		//for(int i=l;i+w-1<=r;i++){
		//	maxi=max(maxi,query(0,0,n-1,i,i+w-1));
		//}
	}
	return res;
}*/
