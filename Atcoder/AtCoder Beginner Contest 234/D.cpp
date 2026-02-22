#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef tree<int,null_type,greater<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int n,k,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    intset res;
    for(int i=0;i<n;i++){
        cin >> a;
        res.insert(a);
        if(i>=k-1){
            cout << *res.find_by_order(k-1) << '\n';
        }
    }
    
}