#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
set<ll> nums;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<10;i++){
        nums.insert(i);
        for(int j=0;j<10;j++){
            ll dif=j-i;
            ll a=i,last=j;
            while(last>=0 && last<=9 && a<=1e18){
                a*=10;
                a+=last;
                nums.insert(a);
                last+=dif;
            }
        }
    }
    cout << *nums.lower_bound(n);
}