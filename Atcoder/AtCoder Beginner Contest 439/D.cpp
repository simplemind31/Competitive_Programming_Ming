#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
ll n,res=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<ll> nums(n);
    map<ll,ll> con,con2;
    for(int i=0;i<n;i++){
        cin >> nums[i];
        if(nums[i]%5==0){
            res+=con[nums[i]/5*7]*con[nums[i]/5*3];
        }
        con[nums[i]]++;
    }
    for(int i=n-1;i>=0;i--){
        if(nums[i]%5==0){
            res+=con2[nums[i]/5*7]*con2[nums[i]/5*3];
        }
        con2[nums[i]]++;
    }
    cout << res;
}