#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,t,nums[100000],psum[100000],con;
ll tot,posi=-1,posj;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k >> t;
    cin >> con;
    for(int i=1;i<n;i++){
        cin >> nums[i];
        nums[i]-=con;
        psum[i]=psum[i-1]+nums[i];
    }
    tot=(n)*nums[n-1]-psum[n-1];
    for(int i=0;i<n;i++){
        //build i;
        ll x=upper_bound(nums,nums+n,nums[i]+k)-nums-1;
        // de i a x;
        // todos menor que i al i
        ll temp=i*nums[i]-((i==0)?0:psum[i-1]);
        temp+=(i+1)*t;
        // todos entre i+1 al x
        temp+=(x-(i+1)+1)*nums[x]-(psum[x]-psum[i]);
        // todos menor o igual que x al n-1
        temp+=(x+1)*(nums[n-1]-nums[x]);
        // todos del x+1 al n-1
        temp+=((n-1)-(x+1)+1)*nums[n-1]-(psum[n-1]-psum[x]);
        if(temp<tot){
            tot=temp;
            posi=i;
            posj=x;
        }
    }
    if(posi==-1){
        cout << -1;
    }else{
        cout << posi+1 << ' ' << posj+1 << ' ' << tot;
    }
}