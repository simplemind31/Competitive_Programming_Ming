#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int nums[n],mini[n],res=mini[n-1]=1e9;
        for(int i=0;i<n;i++)cin >> nums[i];
        sort(nums,nums+n);
        for(int i=n-2;i>=0;i--){
            mini[i]=min(mini[i+1],nums[i+1]-nums[i]);
            if(i+2<n)res=min(res,nums[i+1]-nums[i]+mini[i+2]);
        }
        cout << res << '\n';
    }
}