#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,maxi=-1e9,mini=1e9;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    if(n%2==0){
        cout << n/2;
        return 0;
    }
    for(int i=3;i<n;i+=2){
        if(n%i==0){
            cout << n/i;
            return 0;
        }
    }
}