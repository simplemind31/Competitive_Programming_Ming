#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> intset;
ll n,k;
struct segment{
    int tam;
    vector<ll> st;
    ll eval(pair<ll,ll> line,ll pos){
        return (pos-line.first+1)*line.second;
    }
    void update1(int node,int l,int r,int i,int j,ll val){
        if(r<i || j<l || val<=st[node])return;
        if(i<=l && r<=j){
            st[node]=val;
            return;
        }
        int mid=(l+r)>>1,hiji=node<<1|1,hijd=(node<<1)+2;
        update1(hiji,l,mid,i,j,val);
        update1(hijd,mid+1,r,i,j,val);
    }
    vector<pair<ll,ll>> st2;
    void update2(int node,int l,int r,int i,int j,pair<ll,ll> line){
        // para que usamos val si para ambos extremos l y r st2[node] es mejor?
        if(r<i || j<l)return;
        int mid=(l+r)>>1,hiji=node<<1|1,hijd=(node<<1)+2;
        bool mejoriz=eval(line,l)>eval(st2[node],l);
        bool mejormid=eval(line,mid)>eval(st2[node],mid);
        if(i<=l && r<=j){
            // su punto de interseccion <=mid?
            if(mejormid)swap(st2[node],line);
            if(l==r)return;
            if(mejoriz!=mejormid)update2(hiji,l,mid,i,j,line);
            else update2(hijd,mid+1,r,i,j,line);
            return;
        }
        update2(hiji,l,mid,i,j,line);
        update2(hijd,mid+1,r,i,j,line);
    }
    ll query(int node,int l,int r,int pos){
        ll answer=max(st[node],eval(st2[node],pos));
        if(l==r)return answer;
        int mid=(l+r)>>1,hiji=node<<1|1,hijd=(node<<1)+2;
        if(pos<=mid)return max(answer,query(hiji,l,mid,pos));
        return max(answer,query(hijd,mid+1,r,pos));
    }
    segment(int x){
        tam=x;
        st.resize(4*tam);
        st2.resize(4*tam);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    ll nums[n+2],iz[n+2],de[n+2];
    nums[0]=nums[n+1]=0;
    iz[0]=iz[n+1]=0;
    de[0]=de[n+1]=n+1;
    stack<int> mono;
    mono.push(0);
    for(int i=1;i<=n;i++){
        cin >> nums[i];
        while(nums[i]<=nums[mono.top()])mono.pop();
        iz[i]=mono.top()+1;
        mono.push(i);
    }
    while(!mono.empty())mono.pop();
    mono.push(n+1);
    for(int i=n;i>=1;i--){
        while(nums[i]<=nums[mono.top()])mono.pop();
        de[i]=mono.top()-1;
        mono.push(i);
    }
    segment clav(n+2),clav2(n+2);
    for(int i=1;i<=n;i++){
        /*
        si hay windows que empiezan antes de iz[i] y terminan despues de de[i] entonces pueden (de[i]-iz[i]+1)*nums[i]
        osea termian <=iz[i]+k-1 y terminan>=de[i]
        osea termina [de[i],iz[i]+k-1]
        clav.update1(0,0,n+1,de[i],iz[i]+k-1,(de[i]-iz[i]+1)*nums[i]);

        si hay windows que empiezan >=iz[i] y terminan <=de[i] entonces pueden k*nums[i]
        -> terminan >=iz[i]+k-1 y terminan<=de[i]
        terminan [iz[i]+k-1,de[i]]
        clav.update1(0,0,n+1,iz[i]+k-1,de[i],k*nums[i]);

        si empiezan <=iz[i] y terminan <=de[i];
        terminan <=min(iz[i]+k-1,de[i])
        si termina en iz[i] puede num[i];
        si termina en iz[i]+1 puede 2*nums[i]
        clav.update2(0,0,n+1,iz[i],min(iz[i]+k-1,de[i]),{iz[i],nums[i]});

        si empiezan >=iz[i] y terminan >=de[i]
        -> inverso del anterior
        */
        clav.update1(0,0,n+1,de[i],iz[i]+k-1,(de[i]-iz[i]+1)*nums[i]);
        clav.update1(0,0,n+1,iz[i]+k-1,de[i],k*nums[i]);
        clav.update2(0,0,n+1,iz[i],min(iz[i]+k-1,de[i]),{iz[i],nums[i]});
        ll nueiz=n-de[i]+1;
        ll nuede=n-iz[i]+1;
        iz[i]=n-iz[i]+1;
        de[i]=n-de[i]+1;
        clav2.update2(0,0,n+1,nueiz,min(nueiz+k-1,nuede),{nueiz,nums[i]});
    }
    for(int i=k;i<=n;i++)cout << max(clav.query(0,0,n+1,i),clav2.query(0,0,n+1,n-i+k)) << ' ';
}