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
int n,m;
ll sumpos,posi,sum,maxi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vi b(n),w(m);
    for(int i=0;i<n;i++)cin >> b[i];
    for(int j=0;j<m;j++)cin >> w[j];
    sort(REV(b));
    sort(REV(w));
    m=min(n,m);
    for(;posi<n && b[posi]>=0;posi++)sumpos+=b[posi];
    posi--;
    maxi=sumpos;
    for(int i=0;i<m;i++){
        sum+=w[i];
        if(posi<i)sum+=b[i];
        maxi=max(maxi,sum+sumpos);
    }
    cout << maxi;
}