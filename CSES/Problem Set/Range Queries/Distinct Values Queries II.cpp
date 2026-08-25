#include <bits/stdc++.h>
using namespace std;
struct segment{
    int tam;
    vector<int> res;
    void update(int node,int l,int r,int pos,int val){
        if(l==r){
            res[node]=val;
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(pos<=mid)update(hiji,l,mid,pos,val);
        else update(hijd,mid+1,r,pos,val);
        res[node]=min(res[hiji],res[hijd]);
    }
    int query(int node,int l,int r,int i,int j){
        if(r<i || j<l)return 1e9;
        if(i<=l && r<=j)return res[node];
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return min(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
    }
    segment(int x){
        tam=x;
        res.resize(4*tam);
    }
};
int n,q,a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    int nums[n];
    for(int i=0;i<n;i++)cin >> nums[i];
    segment clav(n);
    map<int,set<int>> conj;
    for(int i=n-1;i>=0;i--){
        //cual es el siguiente nums[i];
        if(conj[nums[i]].empty())clav.update(0,0,n-1,i,1e9);
        else clav.update(0,0,n-1,i,*conj[nums[i]].begin());
        conj[nums[i]].insert(i);
    }
    while(q--){
        cin >> a >> b >> c;
        if(a==2){
            cout << ((clav.query(0,0,n-1,b-1,c-1)<=c-1)?"NO":"YES") << '\n';
            continue;
        }
        b--;
        auto p=conj[nums[b]].lower_bound(b);
        if(p!=conj[nums[b]].begin()){
            if(next(p)!=conj[nums[b]].end())clav.update(0,0,n-1,*prev(p),*next(p));
            else clav.update(0,0,n-1,*prev(p),1e9);
        }
        conj[nums[b]].erase(b);
        nums[b]=c;
        // el anterior
        p=conj[nums[b]].lower_bound(b);
        if(p!=conj[nums[b]].begin())clav.update(0,0,n-1,*prev(p),b);
        if(p!=conj[nums[b]].end())clav.update(0,0,n-1,b,*p);
        else clav.update(0,0,n-1,b,1e9);
        conj[nums[b]].insert(b);
    }
}