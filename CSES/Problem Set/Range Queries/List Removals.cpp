#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
int n,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    indexed_set clav;
    for(int i=0;i<n;i++){
        cin >> a;
        clav.insert({i,a});
    }
    while(n--){
        cin >> a;
        cout << clav.find_by_order(a-1)->second << ' ';
        clav.erase(clav.find_by_order(a-1));
    }
}