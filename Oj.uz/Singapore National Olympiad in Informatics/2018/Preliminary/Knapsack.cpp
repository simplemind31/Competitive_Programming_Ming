#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
#define MOD 998244353
using namespace std;
typedef long long ll;
int s,n,a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> s >> n;
    vector<pair<int,int>> posi[s+1];
    for(int i=0;i<n;i++){
        cin >> a >> b >> c;
        posi[b].push_back({a,c});
    }
    vector<pair<int,int>> tot;
    for(int i=1;i<=s;i++){
        // solo tomar 2000/i de este tipo
        sort(REV(posi[i]));
        int can=0;
        int j=0;
        while(can++<(s-1)/i+1 && j<posi[i].size()){
            tot.push_back({i,posi[i][j].first});
            posi[i][j].second--;
            if(posi[i][j].second==0)j++;
        }
    }
    ll dp[s+1];
    memset(dp,0,sizeof(dp));
    n=tot.size();
    for(int i=0;i<n;i++){
        for(int j=s;j>=tot[i].first;j--){
            dp[j]=max(dp[j],dp[j-tot[i].first]+tot[i].second);
        }
    }
    cout << dp[s];
}