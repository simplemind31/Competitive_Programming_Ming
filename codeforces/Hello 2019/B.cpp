#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int nums[n];
    for(int i=0;i<n;i++)cin >> nums[i];
    for(int i=0;i<(1<<n);i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j))sum=(sum+nums[j])%360;
            else sum=(sum-nums[j]+360)%360;
        }
        if(sum==0){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}