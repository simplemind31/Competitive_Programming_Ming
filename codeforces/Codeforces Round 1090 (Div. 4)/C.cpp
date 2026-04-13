#include <bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int mini=1,maxi=n*3;
        while(mini<=maxi)cout << mini++ << ' ' << maxi-- << ' ' << maxi-- << ' ';
        cout << '\n';
    }
}