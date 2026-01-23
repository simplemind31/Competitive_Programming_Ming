#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll sum,sq,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> a;
        sq-=a*a;
        sum+=a;
    }
    cout << (sum*sum+sq)/2;
}