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
int t=1,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        if(n/3600<10)cout << "0" << n/3600 << ':';
        else cout << n/3600 << ':';
        n%=3600;
        if(n/60<10)cout << '0' << n/60 << ':';
        else cout << n/60 << ':';
        n%=60;
        if(n<10)cout << '0' << n;
        else cout << n;
        cout << '\n';
    }
}