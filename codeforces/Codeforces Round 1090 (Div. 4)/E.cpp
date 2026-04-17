#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> nums(n);
        int x=0;
        for(int i=0;i<n;i++){
            cin >> nums[i];
            for(int j=i-1;j>=0;j--)x=max(x,nums[i]^nums[j]);
        }
        cout << x << '\n';
    }
}