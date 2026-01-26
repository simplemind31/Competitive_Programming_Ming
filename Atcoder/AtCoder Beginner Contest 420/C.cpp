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
char c;
int n,q,a[200000],b[200000],x,y;
ll sum;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<n;i++){
        cin >> b[i];
        sum+=min(a[i],b[i]);
    }
    while(q--){
        cin >> c >> x >> y;
        x--;
        sum-=min(a[x],b[x]);
        ((c=='A')?a[x]:b[x])=y;
        sum+=min(a[x],b[x]);
        cout << sum << '\n';
    }
}