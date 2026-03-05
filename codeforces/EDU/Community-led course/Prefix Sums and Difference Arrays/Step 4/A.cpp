#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,q,a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<ll> nums(n+2);
    for(int i=1;i<=n;i++){
        cin >> a;
        nums[i]+=a;
        nums[i+1]-=a;
    }
    cin >> q;
    while(q--){
        cin >> a >> b >> c;
        nums[a]+=c;
        nums[b+1]-=c;
    }
    for(int i=1;i<=n;i++){
        cout << (nums[i]+=nums[i-1]) << ' ';
    }
}