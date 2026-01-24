#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int nums[100],n,k,res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)cin >> nums[i];
    cin >> k;
    for(int i=0;i<n;i++)res+=(k<=nums[i]);
    cout << res;
}