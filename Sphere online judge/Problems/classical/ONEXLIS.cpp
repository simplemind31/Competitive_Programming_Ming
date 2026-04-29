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
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> nums(n),dp1(n),dp2(n);// end,start
        // lnds tha
        // 3 3 5 6
        multiset<pair<int,int>> lnds;
        lnds.insert({0,0});
        set<int> diff;
        for(int i=0;i<n;i++){
            cin >> nums[i];
            diff.insert(nums[i]);
            auto p=lnds.upper_bound({nums[i],1e9});
            auto ante=prev(p);
            if(p!=lnds.end())lnds.erase(p);
            lnds.insert({nums[i],dp1[i]=ante->second+1});
        }
        vector<int> ord(ALL(diff));
        if(n==1){
            cout << "1\n";
            continue;
        }
        /*for(int i=0;i<n;i++)cout << dp1[i] << ' ';
        cout << '\n';*/
        lnds.clear();
        lnds.insert({1e9+7,0});
        lnds.insert({0,0});
        for(int i=n-1;i>=0;i--){
            auto p=--lnds.lower_bound({nums[i],0});
            auto sig=next(p);
            if(p!=lnds.begin())lnds.erase(p);
            lnds.insert({nums[i],dp2[i]=sig->second+1});
        }
        /*for(int i=0;i<n;i++)cout << dp2[i] << ' ';
        cout << '\n';*/
        int tempmaxi=0,res=0;
        // transformar nums
        segment clav(ord.size());
        for(int i=n-1;i>=0;i--){
            nums[i]=lower_bound(ALL(ord),nums[i])-ord.begin();
            // solo elegir los que son menor nums[i]
            int maxi=clav.query(0,nums[i]-1);
            if(maxi>0)res=max(res,dp1[i]+maxi);
            clav.update(nums[i],dp2[i]);
            // end en i luego nums[i]>nums[j] para i<j
        }
        cout << res << '\n';
    }
}