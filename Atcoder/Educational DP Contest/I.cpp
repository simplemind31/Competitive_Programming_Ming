#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
int n;
double dp[3000],p;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    dp[0]=1;
    for(int i=0;i<n;i++){
        cin >> p;
        for(int j=n;j>=1;j--){
            dp[j]=dp[j]*(1-p)+dp[j-1]*p;
        }
        dp[0]*=(1-p);
    }
    p=0;
    for(int i=(n+1)/2;i<=n;i++){
       p+=dp[i];
    }
    cout << fixed << setprecision(12) << p;
}