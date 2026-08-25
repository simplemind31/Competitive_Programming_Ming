#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n,k;
map<int,int> con;
set<pair<int,int>> clav;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    int nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
        clav.insert({0,nums[i]});
    }
    for(int i=0;i<k-1;i++){
        clav.erase({-con[nums[i]],nums[i]});
        con[nums[i]]++;
        clav.insert({-con[nums[i]],nums[i]});
    }
    for(int i=k-1;i<n;i++){
        clav.erase({-con[nums[i]],nums[i]});
        con[nums[i]]++;
        clav.insert({-con[nums[i]],nums[i]});
        cout << clav.begin()->second << ' ';
        clav.erase({-con[nums[i-k+1]],nums[i-k+1]});
        con[nums[i-k+1]]--;
        clav.insert({-con[nums[i-k+1]],nums[i-k+1]});
    }
}