#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
int n,a;
ll res=1;
map<int,int> con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--)con[cin>>a,a]++;
    for(auto u:con)res=res*(u.second+1)%MOD;
    cout << (res=(res+MOD-1)%MOD);
}