#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
bool xd;
int n,t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        xd=false;
        cin >> n;
        int nums[n];
        vector<int> res;
        for(int i=0;i<n;i++)cin >> nums[i];
        for(int i=n-1;i>=0;i--){
            if((nums[i]>0)^xd){
                xd=!xd;
                res.push_back(i+1);
            }
        }
        cout << res.size() << '\n';
        for(auto u:res)cout << u << ' ';
        cout << '\n';
    }
}