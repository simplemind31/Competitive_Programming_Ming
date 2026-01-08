#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll q,n,a,b;
ll nums[200000];
vector<ll> stt[800005];
/*
i,j -> maxsufixsum,maxprefixsum,suma,res
*/
void init(ll node,ll l,ll r){
    if(l==r){
        stt[node]={nums[l],nums[l],nums[l],nums[l]};
        return;
    }
    ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
    init(hiji,l,mid);
    init(hijd,mid+1,r);
    stt[node]={0,0,0,0};
    stt[node][0]=max(stt[hijd][0],stt[hijd][2]+stt[hiji][0]);
    stt[node][1]=max(stt[hiji][1],stt[hiji][2]+stt[hijd][1]);
    stt[node][2]=stt[hiji][2]+stt[hijd][2];
    stt[node][3]=max({stt[hiji][3],stt[hijd][3],stt[hiji][0]+stt[hijd][1]});
    stt[node][3]=max({stt[node][3],stt[node][0],stt[node][1]});
}
vector<ll> query(ll node,ll l,ll r,ll iz,ll de){
    if(iz<=l && r<=de){
        return stt[node];
    }
    if(de<l || r<iz){
        return {-15008,-15008,-15008,-15008};
    }
    ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
    vector<ll> fir=query(hiji,l,mid,iz,de),seg=query(hijd,mid+1,r,iz,de);
    vector<ll> res(4);
    res[0]=max(seg[0],seg[2]+fir[0]);
    res[1]=max(fir[1],fir[2]+seg[1]);
    res[2]=fir[2]+seg[2];
    res[3]=max({fir[3],seg[3],fir[0]+seg[1]});
    res[3]=max({res[3],res[0],res[1]});
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i=0;i<n;i++)cin >> nums[i];
    init(0,0,n-1);
    cin >> q;
    while(q--){
        cin >> a >> b;
        cout << query(0,0,n-1,a-1,b-1)[3] << '\n';
    }
}
