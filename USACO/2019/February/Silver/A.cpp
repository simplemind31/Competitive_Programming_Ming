#include <bits/stdc++.h>
using namespace std;
int n,mini,iz;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("herding.in","r",stdin);
    //freopen("herding.out","w",stdout);
    cin >> n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    sort(nums,nums+n);
    for(int i=0;i<n;i++){
        int tot=nums[i]-nums[iz]+1;
        int usados=i-iz+1;
        int sobra=tot-usados;
        int need=n-usados;
    }
}