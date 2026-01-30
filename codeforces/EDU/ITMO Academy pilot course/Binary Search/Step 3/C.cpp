#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,l,r=1000000002;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    int nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    while(l<r){
        int mid=(l+r+1)>>1;
        int last=-(1e9)-5;
        int con=0;
        for(int i=0;i<n;i++){
            if(nums[i]-last>=mid){
                con++;
                last=nums[i];
            }
        }
        if(con<k)r=mid-1;
        else l=mid;
    }
    cout << l;
}