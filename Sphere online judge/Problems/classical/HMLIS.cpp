#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,a;
struct segment{
    int tam;
    vector<pair<int,int>> st;
    pair<int,int> merge(pair<int,int>& a,pair<int,int>& b){
        if(a.first>b.first)return a;
        else if(a.first<b.first)return b;
        else return {a.first,(a.second+b.second)%MOD};
    }
    void update(int pos,pair<int,int>& val){for(st[pos]=merge(st[pos+=tam],val);pos;pos>>=1)st[pos>>1]=merge(st[pos],st[pos^1]);}
    pair<int,int> query(int l,int r){
        pair<int,int> res={0,0};
        for(l+=tam,r+=tam;l<=r;l>>=1,r>>=1){
            if(l&1)res=merge(res,st[l++]);
            if(!(r&1))res=merge(res,st[r--]);
        }
        return res;
    }
    segment(int x){st.assign(2*(tam=x),{-1e9,0});}
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin >> nums[i];
    set<int> temp(ALL(nums));
    vector<int> ord(ALL(temp));
    segment clav(ord.size()+1);
    pair<int,int> nada={0,1};
    clav.update(0,nada);
    for(int i=0;i<n;i++){
        nums[i]=lower_bound(ALL(ord),nums[i])-ord.begin()+1;
        pair<int,int> res=clav.query(0,nums[i]-1);
        res.first++;
        clav.update(nums[i],res);
    }
    pair<int,int> res=clav.query(0,ord.size());
    cout << res.first << ' ' << res.second;
}