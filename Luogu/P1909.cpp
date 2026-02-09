#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,c,p,mini=1e9;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<3;i++){
        cin >> c >> p;
        if(((n-1)/c+1)*p<mini)mini=((n-1)/c+1)*p;
    }
    cout << mini;
}