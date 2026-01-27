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
string s,t;
bool a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> s >> t;
    a=s=="sick";
    b=t=="sick";
    if(a&&b)cout << 1;
    else if(a)cout << 2;
    else if(b)cout << 3;
    else cout << 4;
}