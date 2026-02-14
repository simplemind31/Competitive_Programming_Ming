#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool xd=true;
int n;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> s;
    if(s=="0"){
        cout << 0;
        return 0;
    }
    if(s[0]=='-'){
        cout << '-';
        s.erase(s.begin());
    }
    n=s.size();
    for(int i=n-1;i>=0;i--){
        if(xd && s[i]=='0')continue;
        if(s[i]!=0)xd=false;
        cout << s[i];
    }
}