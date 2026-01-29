#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,iz,de;
long double l,r=1e10;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    pair<int,int> nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i].first >> nums[i].second;
    }
    while(abs(r-l)>=1e-7){
        long double mid=(l+r)/2;
        long double nue[n];
        for(int i=0;i<n;i++){
            nue[i]=nums[i].first-nums[i].second*mid;
        }
        sort(nue,nue+n);
        reverse(nue,nue+n);
        long double suma=0;
        for(int i=0;i<k;i++){
            suma+=nue[i];
        }
        if(suma>=0)l=mid;
        else r=mid;
    }
    cout << fixed << setprecision(12) << l;
}