#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
int x,y,p,q;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> p >> q >> x >> y;
    if(x>=p && x<=p+99 && y>=q && y<=q+99){
        cout << "Yes";
    }else{
        cout << "No";
    }
}