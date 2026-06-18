#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
ll n,m,q,a,maxi,completa,last;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> q;
    vector<ll> con(m);
    for(ll i=0;i<n;i++){
        cin >> a;
        maxi=max(maxi,++con[--a]);
    }
    vector<pair<ll,ll>> ord(m);
    for(ll i=0;i<m;i++)ord[i]={con[i],i};
    sort(ALL(ord));
    completa=m*maxi-n;
    vector<ll> psum(m),pmini(m);
    pmini[0]=ord[0].second;
    for(ll i=1;i<m;i++){
        psum[i]=psum[i-1]+(ord[i].first-ord[i-1].first)*i;
        pmini[i]=min(pmini[i-1],ord[i].second);
    }
    vector<ll> ans(q);
    vector<pair<pair<ll,ll>,ll>> cola;
    for(ll i=0;i<q;i++){
        cin >> a;
        a-=n;
        if(a>completa){
            a-=completa;
            ans[i]=(a-1)%m+1;
            continue;
        }
        ll l=0,r=m-1;
        while(l<r){
            ll mid=(l+r+1)>>1;
            // necesito psum[mid] para completar todos los de [0,mid-1] para llegar a ord[mid]
            if(a<=psum[mid])r=mid-1;
            else l=mid;
        }
        ll pos=l;
        // puedo completar para que todos los de [0,pos] llegen a ord[pos].first
        // pero no pueden llegar a ord[pos+1].first+1
        a-=psum[pos];
        // todos son >=mid?
        // a>0
        a=(a-1)%(pos+1)+1;
        // encotrar el a-th de menor entre 0 y pos
        cola.push_back({{pos,a},i});
    }
    sort(ALL(cola));
    indexed_set clav;
    for(auto u:cola){
        while(last<=u.first.first)clav.insert(ord[last++].second);
        ans[u.second]=*clav.find_by_order(u.first.second-1)+1;
    }
    for(ll i=0;i<q;i++)cout << ans[i] << '\n';
}