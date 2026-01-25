#include <bits/stdc++.h>
using namespace std;
int n,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("sleepy.in","r",stdin);
    freopen("sleepy.out","w",stdout);
    cin >> n;
    int nums[n];
    for(int i=0;i<n;i++)cin >> nums[i];
    for(int i=n-2;i>=0;i--){
        if(nums[i]>nums[i+1]){
            cout << i+1;
            return 0;
        }
    }
    cout << 0;
}