#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef vector<int> vi;
typedef pair<int,int> pii;
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<pii> nums(n);
        for(int i=0;i<n;i++){
            scanf("%d %d",&nums[i].first,&nums[i].second);
        }
        sort(nums.begin(),nums.end());
        indexed_set s;
        long long sum=0;
        for(int i=n-1;i>=0;i--){
            s.insert(nums[i].second);
            sum+=s.order_of_key(nums[i].second);
        }
        printf("%lld\n",sum);
    }
}