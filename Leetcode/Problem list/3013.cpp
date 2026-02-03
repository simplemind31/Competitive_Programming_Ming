#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef tree<pair<ll,ll>,null_type,less<pair<ll,ll>>,rb_tree_tag,tree_order_statistics_node_update> llset;
class Solution {
public:
    ll minimumCost(vector<int>& nums, int k, int dist){
        ll n=nums.size(),res=1e18,now=-1;
        llset ahora;
        for(int i=0;i<=k;i++){
            ahora.insert({1e18,now--});
        }
        for(int i=1;i<=dist+1 && i<n;i++){
            ahora.insert({nums[i],i});
        }
        auto p=ahora.begin();
        ll nue=0;
        for(int con=0;con<k-1;con++){
            nue+=p->first;
            p++;
        }
        res=min(res,nue);
        for(int i=2;i+dist<n;i++){
            if(ahora.order_of_key({nums[i-1],i-1})<=k-2){
                nue-=nums[i-1];
                ahora.erase({nums[i-1],i-1});
                nue+=ahora.find_by_order(k-2)->first;
            }else{
                ahora.erase({nums[i-1],i-1});
            }
            if(ahora.order_of_key({nums[i+dist],i+dist})<=k-2){
                nue-=ahora.find_by_order(k-2)->first;
                ahora.insert({nums[i+dist],i+dist});
                nue+=nums[i+dist];
            }else{
                ahora.insert({nums[i+dist],i+dist});
            }
            res=min(res,nue);
        }
        return res+nums[0];
    }
};