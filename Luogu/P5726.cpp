#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int score,n,mini=10,maxi,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        score+=a;
        maxi=max(maxi,a);
        mini=min(mini,a);
    }
    cout << fixed << setprecision(2) << 1.0*(score-maxi-mini)/(n-2);
}