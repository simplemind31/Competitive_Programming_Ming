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
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    pii ord[n+2];
    ord[0]={0,0};
    ord[n+1]={MOD,n+1};
    for(int i=1;i<=n;i++){
        cin >> ord[i].first;
        ord[i].second=i;
    }
    sort(ord+1,ord+n+1);
    for(int i=n;i>=1;i--){
        if(ord[i-1].first!=ord[i].first && ord[i+1].first!=ord[i].first){
            cout << ord[i].second;
            return 0;
        }
    }
    cout << -1;
}