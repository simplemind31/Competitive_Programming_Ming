#include <bits/stdc++.h>
using namespace std;
int n;
long long res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<int> nums(n);
    map<int,bool> chec;
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    int i=0;
    for(int j=0;j<n;j++){
        while(chec[nums[j]])chec[nums[i++]]=false;
        chec[nums[j]]=true;
        res+=j-i+1;
    }
    cout << res;
}