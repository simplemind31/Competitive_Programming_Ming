#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    ll findKthSmallest(vector<int>& coins, int k){
        ll l=0,r=1e18,n=coins.size();
        while(l<r){
            ll mid=(l+r)>>1,can=0;
            // how many inside <=mid
            for(int i=1;i<(1<<n);i++){
                ll div=1;
                for(int j=0;j<n;j++){
                    if(i&(1<<j)){
                        div=lcm(div,coins[j]);
                    }
                }
                if(__builtin_popcount(i)&1)can+=mid/div;
                else can-=mid/div;
            }
            if(can>=k)r=mid;
            else l=mid+1;
        }
        return l;
    }
};