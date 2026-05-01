#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,l;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("guard.in","r",stdin);
    freopen("guard.out","w",stdout);
    cin >> n >> l;
    pair<int,pair<int,int>> cows[n];
    for(int i=0;i<n;i++)cin >> cows[i].first >> cows[i].second.first >> cows[i].second.second;
    pair<int,int> dp[1<<n];
    fill(dp,dp+(1<<n),make_pair(0,-1));
    dp[0]={0,2e9};
    for(int mask=1;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                dp[mask].first+=cows[i].first;
                dp[mask].second=max(dp[mask].second,min(dp[mask^(1<<i)].second-cows[i].second.first,cows[i].second.second));
            }
        }
    }
    int maxi=-1;
    for(int mask=0;mask<(1<<n);mask++){
        if(dp[mask].first>=l){
            maxi=max(maxi,dp[mask].second);
        }
    }
    if(maxi==-1)cout << "Mark is too tall";
    else cout << maxi;
}