#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll res[61]={1},n,t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=1;i<61;i++)res[i]=(i&1)?res[i-1]*2:res[i-1]+1;
    cin >> t;
    while(t--)cout << res[cin>>n,n] << '\n';
}