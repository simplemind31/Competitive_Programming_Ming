#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> intset;
int n,k;
ll res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    intset clav;
    int nums[n];
    for(int i=0;i<k-1;i++){
        cin >> nums[i];
        res+=i-clav.order_of_key({nums[i],1e9});
        clav.insert({nums[i],i});
    }
    for(int i=k-1;i<n;i++){
        cin >> nums[i];
        res+=k-1-clav.order_of_key({nums[i],1e9});
        clav.insert({nums[i],i});
        cout << res << ' ';
        res-=clav.order_of_key({nums[i-k+1],0});
        clav.erase({nums[i-k+1],i-k+1});
    }
}