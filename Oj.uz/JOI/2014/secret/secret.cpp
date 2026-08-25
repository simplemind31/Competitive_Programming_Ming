#include "secret.h"
#include <bits/stdc++.h>
using namespace std;
vector<int> x;
int res[10][1000],mask[1000],n;
void build(int l,int r,int lev){
  if(r==l)return;
  int mid=(l+r)>>1;
  res[lev][mid]=x[mid];
  res[lev][mid+1]=x[mid+1];
  for(int i=mid+2;i<=r;i++)res[lev][i]=Secret(res[lev][i-1],x[i]);
  for(int i=mid-1;i>=l;i--)res[lev][i]=Secret(x[i],res[lev][i+1]);
  for(int i=mid+1;i<=r;i++)mask[i]^=1<<lev;
  build(l,mid,lev+1);
  build(mid+1,r,lev+1);
}
void Init(int N, int A[]){
  x.resize(n=N);
  for(int i=0;i<n;i++)x[i]=A[i];
  build(0,N-1,0);
}
int Query(int L, int R){
  if(L==R)return x[L];
  int pos=__builtin_ctz(mask[L]^mask[R]);
  return Secret(res[pos][L],res[pos][R]);
}