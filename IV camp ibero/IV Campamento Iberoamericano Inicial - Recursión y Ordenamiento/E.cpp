#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int con[100],n,a,maxi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> a;
        maxi=max(maxi,++con[--a]);
    }
    cout << maxi;
}