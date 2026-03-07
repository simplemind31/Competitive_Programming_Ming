#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll maxi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    ll nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
        for(int j=i;j>=0;j--){
            for(int k=j;k>=0;k--){
                maxi=max(maxi,nums[i]|nums[j]|nums[k]);
            }
        }
    }
    cout << maxi;
}