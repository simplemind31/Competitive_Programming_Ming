#include <bits/stdc++.h>
using namespace std;
int n,k;
map<int,int> con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    int nums[n];
    for(int i=0;i<k;i++){
        cin >> nums[i];
        con[nums[i]]++;
    }
    cout << con.size() << ' ';
    for(int i=k;i<n;i++){
        cin >> nums[i];
        con[nums[i]]++;
        if(--con[nums[i-k]]==0)con.erase(nums[i-k]);
        cout << con.size() << ' ';
    }
}