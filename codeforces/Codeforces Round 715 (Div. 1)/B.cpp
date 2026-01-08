#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll t,n,k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll solve[63];
    solve[0]=0;
    solve[1]=1;
    for(ll i=2;i<63;i++){
        solve[i]=solve[i-1]<<1;
        //cout << solve[i] << '\n';
    }
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(n<63 && k>solve[n]){
            cout << "-1\n";
            continue;
        }
        k--;
        vector<ll> nums;
        ll con=0;
        for(ll i=n-1;i>=1;i--){
            if(i>=63){
                nums.push_back(con++);
                continue;
            }
            ll con2=0;
            while(i>0){
                if(k>=solve[i]){
                    k-=solve[i];
                    i--;
                    con2++;
                }else{
                    break;
                }
            }
            while(con2){
                nums.push_back(con+con2);
                con2--;
            }
            nums.push_back(con);
            con=nums.size();
        }
        if(nums.size()<n){
            nums.push_back(n-1);
        }
        for(ll u:nums){
            cout << u+1 << ' ';
        }
        /*cout << endl << endl;
        vector<ll> per(n);
        for(ll i=0;i<n;i++){
            per[i]=i;
        }
        do{
            bool xd=true;
            for(ll i=1;i<n;i++){
                if(!(per[i]+1>=per[i-1])){
                    xd=false;
                    break;
                }
            }
            if(xd){
                for(ll i=0;i<n;i++){
                    cout << per[i]+1 << ' ';
                }
                cout << '\n';
            }
        }while(next_permutation(ALL(per)));*/
        cout << '\n';
    }
}