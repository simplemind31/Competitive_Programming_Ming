#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,temp1,temp2,temp3;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        temp1=(--n)/3;
        temp2=n/5;
        temp3=n/15;
        cout << 3*(temp1)*(temp1+1)/2+5*(temp2)*(temp2+1)/2-15*(temp3)*(temp3+1)/2 << '\n';
    }
}