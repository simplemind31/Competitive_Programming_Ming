#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define sq(x) (x)*(x)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef long long ll;
int n,m,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    multiset<int> nums;
    while(n--){
        cin >> a;
        nums.insert(a);
    }
    while(m--){
        cin >> a;
        if(a==0){
            cin >> a;
            nums.insert(a);
        }else if(a==2){
            cout << *prev(nums.end()) << '\n';
            nums.erase(prev(nums.end()));
        }else{
            cout << *nums.begin() << '\n';
            nums.erase(nums.begin());
        }
    }
}