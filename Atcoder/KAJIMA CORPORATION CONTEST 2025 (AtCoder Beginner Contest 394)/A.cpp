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
int n;
bool cmp(string &a,string &b){return a.size()<b.size();}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    string st[n];
    for(int i=0;i<n;i++)cin >> st[i];
    sort(st,st+n,cmp);
    for(int i=1;i<n;i++)st[0]+=st[i];
    cout << st[0];
}