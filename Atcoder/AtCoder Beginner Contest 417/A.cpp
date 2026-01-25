#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b;
string c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> a >> b >> c;
    for(int i=a;i<n-b;i++){
        cout << c[i];
    }
}
