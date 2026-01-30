#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,d,iz,de;
long double l,r=100;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> d;
    long double nums[n+1];
    nums[0]=0;
    for(int i=1;i<=n;i++){
        cin >> nums[i];
    }
    while(abs(r-l)>=1e-12){
        long double mid=(l+r)/2;
        long double psum[n+1];
        psum[0]=0;
        for(int i=1;i<=n;i++){
            psum[i]=psum[i-1]+nums[i]-mid;
        }
        long double mini=100;
        bool xd=false;
        for(int i=d;i<=n;i++){
            if(psum[i-d]<mini){
                mini=psum[i-d];
            }
            if(psum[i]-mini>=0){
                xd=true;
                break;
            }
        }
        if(xd)l=mid;
        else r=mid;
    }
    long double psum[n+1];
    psum[0]=0;
    for(int i=1;i<=n;i++){
        psum[i]=psum[i-1]+nums[i]-l;
    }
    long double mini=100;
    bool xd=false;
    iz=0;
    for(int i=d;i<=n;i++){
        if(psum[i-d]<mini){
            iz=i-d;
            mini=psum[i-d];
        }
        if(psum[i]-mini>=0){
            xd=true;
            de=i;
            break;
        }
    }
    cout << iz+1 << ' ' << de;
}