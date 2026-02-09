#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int nums[3];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<3;i++)cin >> nums[i];
    sort(nums,nums+3);
    for(int i=0;i<3;i++)cout << nums[i] << ' ';
}