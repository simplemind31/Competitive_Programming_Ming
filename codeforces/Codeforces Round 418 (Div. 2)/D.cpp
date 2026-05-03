#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr double PI = 3.14159265358979323846;
ll n,res;
ll square(ll a){return a*a;}
bool cmp(pair<pair<ll,ll>,ll>& a,pair<pair<ll,ll>,ll>& b){return a.second<b.second;}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int pad[n];
    bool can[n];
    memset(pad,-1,sizeof(pad));
    pair<pair<ll,ll>,ll> dancer[n];
    for(int i=0;i<n;i++)cin >> dancer[i].first.first >> dancer[i].first.second >> dancer[i].second;
    sort(dancer,dancer+n,cmp);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n && pad[i]==-1;j++){
            if(dancer[j].second*dancer[j].second>=square(dancer[j].first.first-dancer[i].first.first)+square(dancer[j].first.second-dancer[i].first.second))pad[i]=j;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(pad[i]==-1){
            res+=square(dancer[i].second);
            can[i]=0;
        }else{
            can[i]=!can[pad[i]];
            if(can[i])res+=square(dancer[i].second);
            else res-=square(dancer[i].second);
        }
    }
    cout << fixed << setprecision(9) << 1.0*res;
}