#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,maxi=-1e9,mini=1e9;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> a;
        maxi=max(maxi,a);
        mini=min(mini,a);
    }
    cout << maxi-mini;
}