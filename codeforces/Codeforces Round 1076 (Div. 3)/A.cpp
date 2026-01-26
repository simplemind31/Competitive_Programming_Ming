#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend();
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
int n,t=1,x,s,sum,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> s >> x;
        sum=0;
        while(n--){
            cin >> a;
            sum+=a;
        }
        if((s-sum>=0)&&(s-sum)%x==0)cout << "YES\n";
        else cout << "NO\n";
    }
}