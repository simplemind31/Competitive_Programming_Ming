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
int t=1,s,k,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> s >> k >> m;
        int sob=m%k;
        if(k>=s){
            //max s
            cout << max(s-sob,0) << '\n';
        }else{
            int can=m/k,son;
            if(can%2==0){
                //s maxi
                cout << max(s-sob,0) << '\n';
            }else{
                //k maxi
                cout << max(k-sob,0) << '\n';
            }
        }
    }
}