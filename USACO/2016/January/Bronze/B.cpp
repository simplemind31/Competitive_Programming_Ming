#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,l,r,maxi=1,powe;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
    cin >> n;
    ll nums[n];
    for(ll i=0;i<n;i++)cin >> nums[i];
    sort(nums,nums+n);
    for(ll i=0;i<n;i++){
        l=r=i;
        powe=1;
        while(true){
            ll newl=l;
            while(newl-1>=0 && nums[newl-1]>=nums[l]-powe)newl--;
            if(newl==l)break;
            l=newl;
            powe++;
        }
        powe=1;
        while(true){
            ll newr=r;
            while(newr+1<n && nums[newr+1]<=nums[r]+powe)newr++;
            if(newr==r)break;
            r=newr;
            powe++;
        }
        maxi=max(maxi,r-l+1);
        //cout << i << ' ' << l << ' ' << r << '\n';
    }
    cout << maxi;
}