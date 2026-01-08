#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A,S,K,X,Y;
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
    cin >> A >> S >> K >> X >> Y;
    if((S+K*Y-A)%(X+Y)==0)cout << (S+K*Y-A)/(X+Y);
    else cout << -1;
}