#include <bits/stdc++.h>
using namespace std;
string a,b;
long long dp[19],res,l,n;
string menos(string x){
    if(x=="1")return "0";
    for(l=x.size()-1;l>=0 && x[l]=='0';x[l--]='9');
    x[l]--;
    reverse(x.begin(),x.end());
    if(x.back()=='0')x.pop_back();
    reverse(x.begin(),x.end());
    return x;
}
long long calc(string x){
    for(int i=res=1;i<(n=x.size());i++)res+=dp[i];
    for(int i=l=0;i<n;i++){
        res+=dp[n-i-1]*(x[i]-'0'-1);
        if(l>=x[i]-'0')res+=dp[n-i-1];
        if(x[i]-'0'==l)return res;
        l=x[i]-'0';
    }
    if(n==1 || (n>=2 && x[n-1]!=x[n-2]))res++;
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(l=dp[0]=1;l<19;l++)dp[l]=dp[l-1]*9;
    cin >> a >> b;
    cout << calc(b)-((a=="0")?0:calc(menos(a)));
}