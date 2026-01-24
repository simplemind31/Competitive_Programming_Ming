#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,ca[1000001],a,b,mini;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        ca[a-1]++;
        ca[b]--;
    }
    mini=ca[0];
    for(int i=1;i<n;i++){
        mini=min(mini,ca[i]+=ca[i-1]);
    }
    cout << mini;
}