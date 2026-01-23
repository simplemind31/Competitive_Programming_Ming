#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,can,a=2;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<64 && a<=n;i++,a<<=1)can+=((ll)sqrt((long double)n/a)+1)>>1;
    cout << can;
}