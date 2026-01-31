#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,m,suma,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    int nums[n];
    ll psum[n];
    for(int i=0;i<n;i++)cin >> nums[i];
    sort(nums,nums+n);
    reverse(nums,nums+n);
    psum[0]=nums[0];
    for(int i=1;i<n;i++)psum[i]=psum[i-1]+nums[i];
    ll l=1,r=2e5;
    while(l<r){
        ll mid=(l+r)>>1,cant=0;
        // solo usar arriba o igual de mid
        ll j=0;
        while(j<n && nums[0]+nums[j]>=mid)j++;
        j--;
        for(int i=0;i<n;i++){
            while(j>=0 && nums[i]+nums[j]<mid)j--;
            if(j<0)break;
            cant+=j+1;
        }
        if(cant<=m)r=mid;
        else l=mid+1;
    }
    ll j=0;
    while(j<n && nums[0]+nums[j]>=l)j++;
    j--;
    for(int i=0;i<n;i++){
        while(j>=0 && nums[i]+nums[j]<l)j--;
        if(j<0)break;
        suma+=nums[i]*(j+1)+psum[j];
        con+=j+1;
    }
    if(con!=m){
        l=1,r=2e5;
        while(l<r){
            ll mid=(l+r+1)>>1,cant=0;
            ll j=0;
            while(j<n && nums[0]+nums[j]>=mid)j++;
            j--;
            for(int i=0;i<n;i++){
                while(j>=0 && nums[i]+nums[j]<mid)j--;
                if(j<0)break;
                cant+=j+1;
            }
            if(cant>=m)l=mid;
            else r=mid-1;
        }
        suma+=(m-con)*l;
    }
    cout << suma;
}