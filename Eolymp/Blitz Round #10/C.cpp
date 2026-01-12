#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
int t,n,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        ll con2=0,suma=0;
        while(n--){
            cin >> a;
            if(a>1)suma++;
            if(a==2)con2++;
        }
        cout << suma*(suma-1)/2-con2*(con2-1)/2 << '\n';       
    }
}