#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    multiset<int> lnds;
    lnds.insert(-1);
    for(int i=1;i<=n;i++){
        cin >> a;
        a-=i;
        if(a<0)continue;
        auto p=lnds.upper_bound(a);
        if(p!=lnds.end())lnds.erase(p);
        lnds.insert(a);
    }
    cout << n-(lnds.size()-1);
}// 0 0 -1 -1 -1