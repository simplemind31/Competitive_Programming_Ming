#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,n;
string st;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> st;
        n=st.size();
        int iz[n],de[n];
        int con=0;
        for(int i=0;i<n;i++){
            if(st[i]=='A')con++;
            else{
                iz[i]=con;
                con=0;
            }
        }
        con=0;
        for(int i=n-1;i>=0;i--){
            if(st[i]=='A')con++;
            else{
                de[i]=con;
                con=0;
            }
        }
        vector<pair<int,int>> B;
        for(int i=0;i<n;i++){
            if(st[i]=='B')B.push_back({iz[i],de[i]});
        }
        n=B.size();
        if(n==0){
            cout << "0\n";
            continue;
        }
        int dp[n][2];
        dp[0][0]=B[0].first;
        dp[0][1]=B[0].second;
        for(int i=1;i<n;i++){
            dp[i][0]=dp[i-1][0]+B[i].first;
            dp[i][1]=max(dp[i-1][0],dp[i-1][1])+B[i].second;
        }
        cout << max(dp[n-1][0],dp[n-1][1]) << '\n';
    }
}