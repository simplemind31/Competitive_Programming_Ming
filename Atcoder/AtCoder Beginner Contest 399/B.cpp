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
int n,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    pair<int,int> ord[n];
    int res[n];
    for(int i=0;i<n;i++){
        cin >> a;
        ord[i]={a,i};
    }
    sort(ord,ord+n);
    reverse(ord,ord+n);
    res[ord[0].second]=1;
    for(int i=1;i<n;i++){
        if(ord[i].first==ord[i-1].first)res[ord[i].second]=res[ord[i-1].second];
        else res[ord[i].second]=i+1;
    }
    for(int i=0;i<n;i++){
        cout << res[i] << '\n';
    }
}