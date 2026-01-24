#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int a,n;
set<int> nums;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> a;
        nums.insert(a);
    }
    cout << nums.size() << '\n';
    for(auto u:nums)cout << u << ' ';
}