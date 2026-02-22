#include <bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin >> t;
    while(t--){
        cin >> n;
        n--;
        int can=1,d=0;
        vector<int> nums;
        while(n){
            if(n-2*can<=0){
                nums.push_back(n-can);
                n=0;
            }else if(n-2*can>=2*can){
                nums.push_back(can);
                can*=2;
                n-=can;
            }else{
                int dif=n/2;
                nums.push_back(dif-can);
                can=dif;
                n-=can;
            }
        }
        cout << nums.size() << '\n';
        for(auto u:nums)cout << u << ' ';
        cout << '\n';
    }
}