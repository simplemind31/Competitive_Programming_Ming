#include <bits/stdc++.h>
using namespace std;
int n,k,res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    k=n-k;
    int nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    sort(nums,nums+n);
    multiset<int> posi;
    for(int i=1;i<k;i++){
        posi.insert(nums[i]-nums[i-1]);
    }
    res=nums[k-1]-nums[0]+*posi.begin();
    for(int i=k;i<n;i++){
        posi.insert(nums[i]-nums[i-1]);
        posi.erase(posi.find(nums[i-k+1]-nums[i-k]));
        res=min(res,nums[i]-nums[i-k+1]+*posi.begin());
    }
    cout << res;
}