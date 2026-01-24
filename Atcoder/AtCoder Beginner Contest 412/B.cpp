#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
bool xd=true;
string s,t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> s >> t;
    for(int i=1;i<s.size() && xd;i++)if(s[i]<='Z' && t.find(s[i-1])==-1)xd=false;
    if(xd)cout << "Yes";
    else cout << "No";
}