#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int t,n,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        intset ay;
        ll res=0;
        cin >> n;
        while(n--){
            cin >> a;
            res+=ay.size()-ay.order_of_key(a);
            ay.insert(a);
        }
        cout << res << '\n';
    }
}
