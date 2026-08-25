#include <bits/stdc++.h>
using namespace std;
int n,k;
bitset<1000001> win;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    int nums[k];
    for(int i=0;i<k;i++)cin >> nums[i];
    for(int i=0;i<=n;i++){
        if(i)cout << (win[i]?'W':'L');
        if(!win[i])for(int j=0;j<k;j++)if(nums[j]+i<=n)win[nums[j]+i]=1;
    }
}