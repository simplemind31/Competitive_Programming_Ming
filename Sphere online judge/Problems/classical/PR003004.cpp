#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t;
ll a,b,power[18];
ll solve(string x){
    ll sumfixed=0,res=0;
    for(int i=0;i<x.size();i++){
        for(int j=0;j<x[i]-'0';j++){
            res+=(sumfixed+j)*power[x.size()-i-1];
            res+=45*(x.size()-i-1)*power[x.size()-i-2];
        }
        sumfixed+=x[i]-'0';
    }
    res+=sumfixed;
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    power[0]=1;
    for(int i=1;i<=18;i++)power[i]=power[i-1]*10;
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << solve(to_string(b))-solve(to_string(max(a-1,0ll))) << '\n';
    }
}