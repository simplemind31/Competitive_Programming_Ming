#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n;
set<string> re;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    string st[n];
    for(int i=0;i<n;i++)cin>>st[i];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(i!=j)re.insert(st[i]+st[j]);
    cout << re.size();
}