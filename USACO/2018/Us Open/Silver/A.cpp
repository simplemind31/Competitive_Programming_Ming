#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int n,maxi,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("sort.in","r",stdin);
    freopen("sort.out","w",stdout);
    cin >> n;
    intset clav;
    for(int i=0;i<n;i++){
        cin >> a;
        clav.insert(a);
        int can=clav.order_of_key(a+1);
        maxi=max(maxi,(int)clav.size()-can);
    }
    cout << maxi+1;
}