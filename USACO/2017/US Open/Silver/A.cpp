#include <bits/stdc++.h>
using namespace std;
int n,mini;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("pairup.in","r",stdin);
    freopen("pairup.out","w",stdout);
    cin >> n;
    pair<int,int> nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i].second >> nums[i].first;
    }
    sort(nums,nums+n);
    int iz=0,de=n-1;
    while(iz<=de){
        mini=max(mini,nums[iz].first+nums[de].first);
        int temp=min(nums[iz].second,nums[de].second);
        nums[iz].second-=temp;
        nums[de].second-=temp;
        if(nums[iz].second<1)iz++;
        if(nums[de].second<1)de--;
    }
    cout << mini << '\n';
}