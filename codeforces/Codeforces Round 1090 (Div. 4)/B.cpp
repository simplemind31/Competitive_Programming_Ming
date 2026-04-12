#include <bits/stdc++.h>
using namespace std;
int t,nums[7];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        for(int i=0;i<7;i++)cin >> nums[i];
        sort(nums,nums+7);
        int suma=0;
        for(int i=0;i<6;i++)suma+=-nums[i];
        suma+=nums[6];
        cout << suma << '\n';
    }
}