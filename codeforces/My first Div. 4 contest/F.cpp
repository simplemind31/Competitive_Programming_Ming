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
int t=1;
ll n,d,u,k,r,a,last,res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> d >> u >> k >> r;
        last=res=0;
        for(int i=0;i<n;i++){
            cin >> a;
            if(last<=a)res+=u*(a-last)+max((ll)((a-last-1)/k),(ll)0)*r;
            else res+=d*(last-a)+max((ll)((last-a-1)/k),(ll)0)*r;
            last=a;
        }
        cout << res << '\n';
    }
}