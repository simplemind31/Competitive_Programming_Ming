#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
long double l,r=2e9;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    pair<long double,long double> nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i].first >> nums[i].second;
    }
    while(abs(r-l)>=1e-7){
        long double mid=(l+r)/2;
        long double iz=-1e9,de=1e9;
        for(int i=0;i<n;i++){
            iz=max(iz,nums[i].first-nums[i].second*mid);
            de=min(de,nums[i].first+nums[i].second*mid);
        }
        if(iz<=de)r=mid;
        else l=mid;
    }
    cout << fixed << setprecision(12) << l;
}