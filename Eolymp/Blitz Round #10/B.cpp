#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
int t;
ll x,y;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> x >> y;
        if(y<=x-1)cout << "9\n";
        else if(y==x)cout << "8\n";
        else if(y>2*x)cout << "-1\n";
        else if(y==2*x)cout << "1\n";
        else cout << "0\n";
    }
}