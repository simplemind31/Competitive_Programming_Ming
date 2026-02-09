#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int t,n;
ll res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int nums[n];
    intset conj,conj2;
    for(int i=0;i<n;i++){
        cin >> nums[i];
        conj.insert(nums[i]);
    }
    for(int i=n-1;i>=0;i--){
        conj.erase(nums[i]);
        conj2.insert(nums[i]);
        res+=1ll*conj2.order_of_key(nums[i])*(conj.size()-conj.order_of_key(nums[i]));
    }
    cout << res;
}