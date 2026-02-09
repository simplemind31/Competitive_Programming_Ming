#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int n,k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    k=min(n-1,k);
    int nums[n],cantimover[n];
    intset ayu,dispo;
    for(int i=0;i<n;i++){
        dispo.insert(i);
        cantimover[i]=0;
    }
    for(int i=0;i<n;i++){
        cin >> nums[i];
        //  cuantos mayores?
        int pos=ayu.order_of_key(nums[i]+1);
        int can=ayu.size()-pos;
        //cout << can << ' ';
        ayu.insert(nums[i]);
        cantimover[i]=min(k,can);
    }
    //cout << '\n';
    int res[n];
    for(int i=n-1;i>=0;i--){
        // sacar la posicion i-cantimover;
        int val=*dispo.find_by_order(i-cantimover[i]);
        //cout << val << ' ';
        res[val]=nums[i];
        dispo.erase(dispo.find_by_order(i-cantimover[i]));
    }
    cout << endl;
    for(int i=0;i<n;i++){
        cout << res[i] << ' ';
    }
}