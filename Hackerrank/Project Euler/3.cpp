#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n,i;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(i=2;i*i<=n;i++){
            while(n%i==0)n/=i;
            if(i*i>n)break;
        }
        if(n==1)cout << i << '\n';
        else cout << n << '\n';
    }
}