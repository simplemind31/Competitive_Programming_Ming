#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a;
ll res;
map<int,int> con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a;
        res+=con[i-a];
        con[i+a]++;
    }
    cout << res;
}