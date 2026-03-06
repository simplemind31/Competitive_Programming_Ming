#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
ll k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        int nums[n],con=1,res=0,mini;
        ll suma=0;
        for(int i=0;i<n;i++){
            cin >> nums[i];
            suma+=nums[i];
        }
        sort(nums,nums+n);
        mini=nums[0];
        for(int i=n-1;i>=1 && suma>k;i--){
            // si quito mini, resto con, si quito ulti quito nums[i]-mini
            if(nums[i]-mini>=con){
                con++;
                res++;
                suma-=nums[i]-mini;
            }else{
                mini--;
                res++;
                suma-=con;
                i++;
            }
        }
        if(suma>k){
            // si quito quito n
            //suma-x*n<=k
            //(suma-k)/n<=x-> ceil
            res+=(suma-k-1)/n+1;
        }
        cout << res << '\n';
    }
}