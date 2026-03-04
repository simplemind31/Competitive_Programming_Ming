#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("sabotage.in","r",stdin);
    freopen("sabotage.out","w",stdout);
    cin >> n;
    int nums[n],psum[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    psum[0]=nums[0];
    for(int i=1;i<n;i++)psum[i]=psum[i-1]+nums[i];
    double l=0,r=10000;
    while(abs(l-r)>=1e-4){
        double mid=(l+r)/2;
        //psum[i]-X*i<=X*(N-j)-S+psum[j]
        // psum[i]-X*i<=XN+psum[j]-Xj-S
        //S-XN<=(psum[j]-Xj)-(psum[i]-Xi);
        double mini=1e9;
        bool xd=false;
        for(int i=0;i<n-1 && !xd;i++){
            if(psum[n-1]-mid*n<=psum[i]-mid*i-mini)xd=true;
            mini=min(mini,psum[i]-mid*i);
        }
        if(xd)r=mid;
        else l=mid;
    }
    cout << fixed << setprecision(3) << l;
}