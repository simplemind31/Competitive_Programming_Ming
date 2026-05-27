#include <bits/stdc++.h>
using namespace std;
int x,res,nums[]={1,5,10,20,50,100};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> x;
    for(int i=5;i>=0;i--){
        res+=x/nums[i];
        x%=nums[i];
    }
    cout << res;
}