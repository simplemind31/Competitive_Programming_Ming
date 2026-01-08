#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,h,n;
pair<int,int> nums[200000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> h >> n;
        for(int i=0;i<n;i++){
            cin >> nums[i].first;
        }
        for(int i=0;i<n;i++){
            cin >> nums[i].second;
        }
        ll l=0,r=1e12;
        while(l<r){
            ll mid=(l+r)>>1,suma=0;
            for(int i=0;i<n;i++){
                suma+=(mid/nums[i].second+1)*nums[i].first;
                if(suma>=h)break;
            }
            if(suma>=h){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        cout << l+1 << '\n';
    }
}