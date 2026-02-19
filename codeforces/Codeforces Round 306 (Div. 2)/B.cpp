#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,l,r,x,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> l >> r >> x;
    int nums[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    for(int mask=0;mask<(1<<n);mask++){
        int suma=0,mini=1e9,maxi=0;
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                suma+=nums[i];
                mini=min(mini,nums[i]);
                maxi=max(maxi,nums[i]);
            }
        }
        if(suma>=l && suma<=r && maxi-mini>=x)con++;
    }
    cout << con;
}