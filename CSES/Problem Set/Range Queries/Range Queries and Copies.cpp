#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct vertex{
    vertex *iz,*de;
    ll sum;
    vertex(int a){
        iz=nullptr;
        de=nullptr;
        sum=a;
    }
    vertex(vertex *x,vertex *y){
        iz=x;
        de=y;
        sum=0;
        if(iz)sum+=iz->sum;
        if(de)sum+=de->sum;
    }
    vertex(vertex *x){
        iz=x->iz;
        de=x->de;
        sum=x->sum;
    }
};
int n,q,a,b,c,d;
vector<ll> nums;
vector<vertex*> versions;
vertex* build(int l,int r){
    if(l==r)return new vertex(nums[l]);
    int mid=(l+r)>>1;
    return new vertex(build(l,mid),build(mid+1,r));
}
ll query(int l,int r,int i,int j,vertex* node){
    if(r<i || j<l)return 0;
    if(i<=l && r<=j)return node->sum;
    int mid=(l+r)>>1;
    return query(l,mid,i,j,node->iz)+query(mid+1,r,i,j,node->de);
}
vertex* update(int l,int r,int pos,int val,vertex* node){
    if(l==r)return new vertex(val);
    int mid=(l+r)>>1;
    if(pos<=mid)return new vertex(update(l,mid,pos,val,node->iz),node->de);
    return new vertex(node->iz,update(mid+1,r,pos,val,node->de));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    nums.resize(n);
    for(int i=0;i<n;i++)cin >> nums[i];
    versions.push_back(build(0,n-1));
    while(q--){
        cin >> a >> b;
        if(a==3)versions.push_back(versions[b-1]);
        else{
            cin >> c >> d;
            if(a==1)versions[b-1]=update(0,n-1,c-1,d,versions[b-1]);
            else cout << query(0,n-1,c-1,d-1,versions[b-1]) << '\n';
        }
    }
}