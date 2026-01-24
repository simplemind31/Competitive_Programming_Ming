#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,maxi;
string s,t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int nums[n];
    map<int,int> con;
    for(int i=0;i<n;i++){
        cin >> nums[i];
        con[nums[i]]++;
    }
    sort(nums,nums+n);
    for(auto u:con){
        if(u.first>100)maxi+=u.second;
    }
    for(int i=100;i>=0;i--){
        maxi+=con[i];
        if(maxi>=i){
            cout << i;
            return 0;
        }
    }
}