#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int t=1,n,k;
map<int,int> res;
int solve(int x){
    if(x<k)return -1;
    if(x==k)return 0;
    if(res[x]!=0)return res[x];
    int a=x/2,b=(x+1)/2;
    if(solve(a)==-1 && solve(b)==-1){
        return res[x]=-1;
    }else if(solve(b)==-1){
        return res[x]=solve(a)+1;
    }else if(solve(a)==-1){
        return res[x]=solve(b)+1;
    }else{
        return res[x]=min(solve(a),solve(b))+1;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        res.clear();
        cout << solve(n) << '\n';
    }
}