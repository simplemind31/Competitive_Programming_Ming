#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("lemonade.in","r",stdin);
    freopen("lemonade.out","w",stdout);
    cin >> n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    sort(nums,nums+n);
    reverse(nums,nums+n);
    int con=0;
    for(int i=0;i<n;i++){
        if(nums[i]>=con)con++;
    }
    cout << con;
}