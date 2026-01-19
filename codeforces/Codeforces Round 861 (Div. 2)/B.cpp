#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m;
ll res,now;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        int nums[m][n];
        for(int i=res=0;i<n;i++)for(int j=0;j<m;j++)cin >> nums[j][i];
        for(int i=0;i<m;i++){
            sort(nums[i],nums[i]+n);
            for(int j=now=0;j<n;j++)res+=1LL*(j+1)*nums[i][j]-(now+=nums[i][j]);
        }
        cout << res << '\n';
    }
}