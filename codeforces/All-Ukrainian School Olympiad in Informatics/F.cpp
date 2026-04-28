#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,v,maxi=1,maxi2;
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
    if(x.first==y.first)return x.second>y.second;
    return x.first<y.first;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    pair<ll,ll> events[n];
    for(ll i=0;i<n;i++)cin >> events[i].second >> events[i].first;
    //sort(events,events+n);
    cin >> v;
    // para ini=0 -> inciamos dp[0]=0
    // para ini=cualquier-> iniciamos dp[i]=max(1,la mejor opcion)
    for(ll i=0;i<n;i++){
        // si events[j].second<=events[i].second viene de izquierda
        // -> events[j].second-events[j].first*v>=events[i].second-events[i].first*v

        // si events[j].second>=events[i].second viene de derecha
        // -> events[j].second+events[j].first*v<=events[i].second+events[i].first*v

        // es obvio que ambas condiciones deben cumplir sea iz o de
        /*
        encontrar j tal cumpla los 3:
        j<=i......1
        events[j].second-events[j].first*v>=events[i].second-events[i].first*v......2
        events[j].second+events[j].first*v<=events[i].second+events[i].first*v......3
        if events[j].second<=events[i].second ->events[j].first<=events[i].first
        if events[j].second>=events[i].second ->events[j].first<=events[i].first
        // ambos casos llevan a events[j].first<=events[i].first
        // pero si events[j].first<=events[i].first -> j<=i
        // asi que si cumple 2 y 3, automaticamente cumple 1
        // -> solo encontrar j tal que cumplan 2:
        events[j].second-events[j].first*v>=events[i].second-events[i].first*v...1
        events[j].second+events[j].first*v<=events[i].second+events[i].first*v...2
        -> sort in ascending by events[i].second+events[i].first*v and find longest no increasing subsequence
        */
        pair<ll,ll> nue={events[i].second+events[i].first*v,events[i].second-events[i].first*v};
        events[i]=nue;
    }
    sort(events,events+n,cmp);
    set<pair<ll,ll>> lis;
    vector<ll> res(n);
    // 3 7 7 8 9 9
    // longest no increasing from left=longest no decreasing from right
    res[n-1]=1;
    lis.insert({events[n-1].second,-(n-1)});
    for(int i=n-2;i>=0;i--){
        auto p=lis.upper_bound({events[i].second,1e18});
        if(p==lis.begin()){
            res[i]=1;
            lis.erase(p);
            lis.insert({events[i].second,-i});
            continue;
        }
        auto ante=prev(p);
        if(p!=lis.end()){
            lis.erase(p);
        }
        lis.insert({events[i].second,-i});
        maxi=max(maxi,res[i]=res[-ante->second]+1);
    }
    for(int i=0;i<n;i++){
        if(events[i].second<=0 && events[i].first>=0)maxi2=max(maxi2,res[i]);
    }
    cout << maxi2 << ' ' << maxi;
}