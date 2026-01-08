#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
int t,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        ll tot=0,con=0,contado=0;
        vector<int> nums(n);
        vector<ll> res(n+1);
        for(int i=0;i<n;i++){
            cin >> nums[i];
        }
        int last2=n;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==2){
                res[i]+=2*res[last2];
                res[i]%=MOD;
                last2=i;
                res[i]+=con;
                res[i]%=MOD;
                con=0;
            }else if(nums[i]==1){
                tot+=2*res[last2];
                tot%=MOD;
            }else if(nums[i]==3){
                con++;
            }
        }
        int ulticheck=n-1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==1){
                tot-=contado;
                tot%=MOD;
                tot+=MOD;
                tot%=MOD; 
            }else if(nums[i]==2){
                while(ulticheck>=i){
                    if(nums[ulticheck]==3){
                        contado++;
                    }
                    ulticheck--;
                }
            }
        }
        cout << tot << '\n';
    }
}