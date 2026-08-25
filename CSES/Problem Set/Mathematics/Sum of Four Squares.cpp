#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;
const int MAXN=10000000;
int t,n;
vector<int> nums,primes;
int representante[MAXN+1];
bitset<MAXN+1> criba;
map<pair<int,int>,vector<int>> dp;
vector<int> mal={-1};
vector<int> solve(int x,int can){
    if(!x)return vector(can,0);
    int mul=x/representante[x];
    // a todas los finales multiplico por x
    if(mul!=1){
        vector<int> res=solve(representante[x],can);
        if(res==mal)return mal;
        for(auto &u:res)u*=mul;
        return res;
    }
    if(dp.count({x,can}))return dp[{x,can}];
    if(can==0)return dp[{x,can}]=mal;
    for(int i=upper_bound(ALL(nums),x)-nums.begin()-1;i>0;i--){
        vector<int> res=solve(x-nums[i],can-1);
        if(res!=mal){
            res.push_back(nums[i]);
            return dp[{x,can}]=res;
        }
    }
    return dp[{x,can}]=mal;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    for(int i=0;i*i<=MAXN;i++)nums.push_back(i*i);
    criba[0]=criba[1]=representante[1]=1;
    for(int i=2;i<=MAXN;i++){
        if(!criba[i]){
            representante[i]=i;
            primes.push_back(i);
        }
        for(int j=0;j<primes.size() && i*primes[j]<=MAXN;j++){
            criba[i*primes[j]]=1;
            representante[i*primes[j]]=i*primes[j];
            if(i%primes[j]==0){
                representante[i*primes[j]]=representante[i/primes[j]];
                break;
            }
        }
    }
    while(t--){
        cin >> n;
        vector<int> res=solve(n,4);
        for(auto u:res)cout << lower_bound(ALL(nums),u)-nums.begin() << ' ';
        cout << '\n';
    }
}