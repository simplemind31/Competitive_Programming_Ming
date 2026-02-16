#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
        int con=0;
        for(int j=0;j<i;j++)if(nums[j]<nums[i])con++;
        cout << con << ' ';
    }
}