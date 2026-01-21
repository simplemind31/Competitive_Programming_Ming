#include <bits/stdc++.h>
using namespace std;
bool pal[5000][5000];
int a,b,con,dp[5000][5000];
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    for(int i=0,n=st.size();i<n;i++,con-=con)for(int j=i;j>=0;j--)dp[j][i]=dp[j][i-1]+(con+=(pal[j][i]|=(i==j)||(st[i]==st[j]&&(i==j+1||pal[j+1][i-1]))));
    cin >> a;
    while(cin >> a >> b)cout << dp[--a][--b] << '\n';
}