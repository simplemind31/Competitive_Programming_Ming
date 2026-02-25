#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll t,n,w;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n >> w;
        ll nums[n];
        for(ll i=0;i<n;i++){
            cin >> nums[i];
        }
        sort(nums,nums+n);
        ll i=1;
        for(;i<n && w;i++){
            if(w-i*(nums[i]-nums[i-1])>0){
                w-=(nums[i]-nums[i-1])*i;
            }else{
                cout << nums[i-1]+w/i << '\n';
                w=0;
            }
        }
        if(w){
            cout << nums[n-1]+w/n << '\n';
        }
    }
}