#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i=2;i*i<=n;i++){
        int con=0;
        while(n%i==0){
            n/=i;
            con++;
        }
        res+=(-1+sqrt(1+8*con))/2;
    }
    if(n!=1)res++;
    cout << res;
}