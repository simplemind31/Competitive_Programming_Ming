#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    ll minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes){
        int n=workerTimes.size();
        ll l=1,r=5000050000000000;
        while(l<r){
            ll mid=(l+r)>>1;
            int suma=0;
            for(int i=0;i<n && suma<mountainHeight;i++){
                /*
                x*(x+1)/2*workerTimes[i]<=mid
                x*(x+1)<=mid*2/workerTimes[i]
                x^2+x-mid*2/workerTimes[i]<=0
                x=(-1+-sqrt(1+8*mid/workerTimes[i]))/2;
                */
                suma+=(-1+sqrt(1+8*mid/workerTimes[i]))/2;
            }
            if(suma>=mountainHeight)r=mid;
            else l=mid+1;
        }
        return l;
    }
};