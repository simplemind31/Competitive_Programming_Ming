#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> nums;
void solve(int iz,int de){
    if(iz>=de)return;
    int pivot=nums[de];
    deque<int> ay;
    for(int i=iz;i<de;i++){
        if(nums[i]<pivot){
            if(!ay.empty()){
                int sw=ay.front();
                ay.pop_front();
                swap(nums[i],nums[sw]);
                ay.push_back(i);
            }
        }else{
            ay.push_back(i);
        }
    }
    if(ay.empty()){
        for(int i=0;i<n;i++){
            cout << nums[i] << ' ';
        }
        cout << '\n';
        solve(iz,de-1);
    }else{
        int sw=ay.front();
        ay.pop_front();
        swap(nums[sw],nums[de]);
        ay.push_back(de);
        for(int i=0;i<n;i++){
            cout << nums[i] << ' ';
        }
        cout << '\n';
        solve(iz,sw-1);
        solve(sw+1,de);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    nums.resize(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    solve(0,n-1);
}