#include <bits/stdc++.h>
using namespace std;
int nums[3];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<3;i++)cin >> nums[i];
    sort(nums,nums+3);
    if(nums[0]+nums[1]<=nums[2])cout << "Not triangle\n";
    else{
        if(nums[0]*nums[0]+nums[1]*nums[1]==nums[2]*nums[2])cout << "Right triangle\n";
        else if(nums[0]*nums[0]+nums[1]*nums[1]>nums[2]*nums[2])cout << "Acute triangle\n";
        else cout << "Obtuse triangle\n";
        if(nums[0]==nums[1] || nums[1]==nums[2]){
            cout << "Isosceles triangle\n";
            if(nums[0]==nums[2])cout << "Equilateral triangle\n";
        }
    }
}