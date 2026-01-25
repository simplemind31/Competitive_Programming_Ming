#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char c;
int n,l,r;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> l >> r;
    for(int i=0;i<n;i++){
        cin >> c;
        if(i>=l-1 && i<=r-1 && c=='x'){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}