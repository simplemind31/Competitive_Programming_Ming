#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll t,n;
string str;
ll tot;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> str;
        n=str.size();
        tot=0;
        vector<ll> psum(n+1);
        map<ll,ll> con;
        con[-1]++;
        for(int i=0;i<n;i++){
            psum[i]=((i==0)?0:psum[i-1])+str[i]-'0';
            tot+=(con[i-2*psum[i]])*(n-i);
            tot%=MOD;
            con[i-2*psum[i]]+=i+2;
        }
        cout << tot << '\n';
    }
}