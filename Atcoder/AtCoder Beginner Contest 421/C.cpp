#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend();
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
ll n,fa,poa,pob=1,fb;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> st;
    for(int i=0;i<2*n;i++){
        if(st[i]=='A'){
            fa+=abs(i-poa);
            fb+=abs(i-pob);
            poa+=2;
            pob+=2;
        }
    }
    cout << min(fa,fb);
}