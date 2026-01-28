#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,q,a,b;
ll suma;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    ll nums[n],psum[n+2];
    for(int i=0;i<n;i++){
        psum[i]=0;
        cin >> nums[i];
    }
    psum[n]=psum[n+1]=0;
    sort(nums,nums+n);
    while(q--){
        cin >> a >> b;
        psum[a]++;
        psum[++b]--;
    }
    for(int i=1;i<=n;i++){
        psum[i]+=psum[i-1];
    }
    sort(psum+1,psum+n+1);
    for(int i=1;i<=n;i++){
        suma+=psum[i]*nums[i-1];
    }
    cout << suma;
}