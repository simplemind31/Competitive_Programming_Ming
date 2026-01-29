#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
ll l,r=1e14;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    int nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
        l=max((ll)nums[i],l);
    }
    while(l<r){
        ll mid=(l+r)>>1;
        ll can=1,suma=0;
        for(int i=0;i<n;i++){
            if(suma+nums[i]<=mid)suma+=nums[i];
            else{
                suma=nums[i];
                can++;
            }
        }
        if(can<=k)r=mid;
        else l=mid+1;
    }
    cout << l;
}