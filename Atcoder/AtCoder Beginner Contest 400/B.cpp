#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum;
int n,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<=m && sum<=1e9;i++)sum+=pow(n,i);
    if(sum<=1e9)cout << sum;
    else cout << "inf";
}