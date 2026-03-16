#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
const int MAXN=10000;
int n,x;
ll dp[MAXN+5],res;
struct segmenttree{
    vector<ll> st;
    void update(int node,int l,int r,int pos,ll val){
        if(l==r){
            st[node]=max(val,st[node]);
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(pos<=mid)update(hiji,l,mid,pos,val);
        else update(hijd,mid+1,r,pos,val);
        st[node]=max(st[hiji],st[hijd]);
    }
    ll query(int node,int l,int r,int i,int j){
        if(r<i ||j<l)return 0;
        if(i<=l && r<=j)return st[node];
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return max(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
    }
    segmenttree(){
        st.resize(4*MAXN+5);
    }
};
bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    if(a.first.second==b.first.second)return a<b;
    return a.first.second<b.first.second;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    pair<pair<int,int>,int> nums[n]; 
    for(int i=0;i<n;i++)cin >> nums[i].first.first >> nums[i].first.second >> nums[i].second;
    // w,s,v
    sort(nums,nums+n,cmp);
    segmenttree clave;
    for(int i=0;i<n;i++){
        //dp[j]=mejor forma si la suma de pesos es j
        for(int j=MAXN;j>=0;j--){
            // para que lleguemos a j, necesitamos que
            if(j-nums[i].first.first<=nums[i].first.second && j-nums[i].first.first>=0)res=max(res,dp[j]=max(dp[j],dp[j-nums[i].first.first]+nums[i].second));
            //dp[j]=max(dp[j],max(dp[0],...,dp[min(j-nums[i].first.second,nums[i].first.first)])+nums[i].second)
        }


        // puedo elegir entre 0 al s
        //ll maxi=clave.query(0,0,MAXN,0,nums[i].first.second);
        /*for(int j=MAXN;j>=min(nums[i].first.first,nums[i].first.first);j--){
            // si la suma vale j, elijo suma que tiene j-nums[i].first.first
            clave.update(0,0,MAXN,j,clave.query(0,0,MAXN,0,min(j-nums[i].first.first,nums[i].first.first))+nums[i].second);
        }*/
    }
    cout << res;
}