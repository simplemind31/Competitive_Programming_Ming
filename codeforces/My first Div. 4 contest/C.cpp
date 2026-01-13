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
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        cin >> st;
        bool xd=false;
        if(st[1]==st[0])xd=true;
        for(int i=2;i<n && !xd;i++)if(st[i]==st[i-1] || st[i]==st[i-2])xd=true;
        if(xd)cout << "0\n";
        else cout << "1\n";
    }
}