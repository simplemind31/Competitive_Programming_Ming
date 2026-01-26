#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend();
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int n,t=1,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        vector<bool> exi(n+1);
        for(int i=0;i<n;i++){
            cin >> a;
            exi[a]=true;
        }
        vi dp(n+1,1e9);
        for(int i=1;i<=n;i++){
            if(exi[i])dp[i]=1;
            else{
                for(int j=1;j*j<=i;j++){
                    if(i%j)continue;
                    if(exi[j] && exi[i/j])dp[i]=2;
                    else dp[i]=min(dp[i],dp[j]+dp[i/j]);
                }
            }
            if(dp[i]==1e9)cout << "-1 ";
            else cout << dp[i] << ' ';
        }
        cout << '\n';
    }
}