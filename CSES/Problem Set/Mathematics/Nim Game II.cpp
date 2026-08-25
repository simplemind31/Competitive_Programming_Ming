#include <bits/stdc++.h>
using namespace std;
int t,n,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        // the grundy number is just mod4
        int x=0;
        for(int i=0;i<n;i++){
            cin >> a;
            x^=a%4;
        }
        cout << (x?"first":"second") << '\n';
    }
}