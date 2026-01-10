#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
int n,q;
ll x,y;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    vector<ll> nums(n+2);
    nums[0]=0;
    for(int i=1;i<=n;i++){
        cin >> nums[i];
    }
    nums[n+1]=1e12;
    sort(ALL(nums));
    vector<pair<ll,ll>> clave;
    clave.push_back({0,0});
    for(int i=1;i<=n+1;i++){
        if(nums[i-1]+1!=nums[i]){
            clave.push_back({nums[i-1]+1,nums[i]-1});
        }
    }
    n=clave.size()-1;
    vector<ll> psum(n+1);
    for(int i=1;i<=n;i++){
        psum[i]=psum[i-1]+clave[i].second-clave[i].first+1;
        //cout << psum[i] << ' ';
    }
    while(q--){
        cin >> x >> y;
        int pos=lower_bound(ALL(clave),make_pair(x,(ll)0))-clave.begin();
        pos--;
        if(x>clave[pos].second){
            pos++;
        }
        if(clave[pos].first>x){
            x=clave[pos].first;
        }
        //completar pos;
        if(clave[pos].second-x+1>=y){
            cout << x+y-1 << '\n';
            continue;
        }
        y-=clave[pos].second-x+1;
        pos++;
        x=clave[pos].first;
        int l=pos,r=n;
        while(l<r){
            int mid=(l+r)>>1;
            if(psum[mid]-psum[pos-1]>=y){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        //res esta en l
        y-=psum[l-1]-psum[pos-1];
        pos=l;
        x=clave[pos].first;
        cout << x+y-1 << '\n';
    }
}