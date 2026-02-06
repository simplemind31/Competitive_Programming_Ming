#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int l,n,f,b,pos;
ll res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("reststops.in","r",stdin);
    freopen("reststops.out","w",stdout);
    cin >> l >> n >> f >> b;
    pair<int,int> stop[n];
    for(int i=0;i<n;i++){
        cin >> stop[i].second >> stop[i].first;
    }
    sort(stop,stop+n);
    reverse(stop,stop+n);
    for(int i=0;i<n;i++){
        if(stop[i].second<=pos)continue;
        // hay stop[i].second-pos de dist, 
        res+=1ll*(stop[i].second-pos)*(f-b)*stop[i].first;
        pos=stop[i].second;
    }
    cout << res;
}