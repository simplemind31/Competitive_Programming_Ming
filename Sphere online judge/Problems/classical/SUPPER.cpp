#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,n;
struct segment{
    int tam;
    vector<int> st;
    void update(int pos,int val){for(st[pos]=max(st[pos+=tam],val);pos;pos>>=1)st[pos>>1]=max(st[pos],st[pos^1]);}
    int query(int l,int r){
        int res=0;
        for(l+=tam,r+=tam;l<=r;l>>=1,r>>=1){
            if(l&1)res=max(res,st[l++]);
            if(!(r&1))res=max(res,st[r--]);
        }
        return res;
    }
    segment(int x){st.assign(2*(tam=x),-1e9);}
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    t=10;
    while(t--){
        cin >> n;
        int lis=0;
        vector<int> nums(n),dp1(n),dp2(n);
        multiset<pair<int,int>> lnds;
        lnds.insert({0,0});
        for(int i=0;i<n;i++){
            cin >> nums[i];
            auto p=lnds.upper_bound({nums[i],1e9});
            auto ante=prev(p);
            if(p!=lnds.end())lnds.erase(p);
            lnds.insert({nums[i],dp1[i]=ante->second+1});
            lis=max(lis,dp1[i]);
        }
        lnds.clear();
        lnds.insert({1e9+7,0});
        lnds.insert({0,0});
        for(int i=n-1;i>=0;i--){
            auto p=--lnds.lower_bound({nums[i],0});
            auto sig=next(p);
            if(p!=lnds.begin())lnds.erase(p);
            lnds.insert({nums[i],dp2[i]=sig->second+1});
        }
        vector<int> res;
        int maxi=0,con=0;
        for(int i=0;i<n;i++){
            if(dp1[i]+dp2[i]-1==lis){
                res.push_back(nums[i]);
            }
        }
        sort(ALL(res));
        cout << res.size() << '\n';
        for(auto u:res)cout << u << ' ';
        cout << '\n';
    }
}