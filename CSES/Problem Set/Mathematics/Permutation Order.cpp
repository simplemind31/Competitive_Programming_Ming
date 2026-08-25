#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
ll n,t,c,k,fact[21];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    fact[0]=1;
    for(int i=1;i<=20;i++)fact[i]=fact[i-1]*i;
    while(t--){
        cin >> c >> n;
        intset posibles;
        for(int i=0;i<n;i++)posibles.insert(i);
        if(c==1){
            cin >> k;
            for(int i=n-1;i>=0;i--){
                ll x=(k-1)/fact[i];
                cout << *posibles.find_by_order(x)+1 << ' ';
                posibles.erase(posibles.find_by_order(x));
                k-=x*fact[i];
            }
        }else{
            ll res=1;
            for(int i=n-1;i>=0;i--){
                cin >> k;
                res+=posibles.order_of_key(k-1)*fact[i];
                posibles.erase(k-1);
            }
            cout << res;
        }
        cout << '\n';
    }
}