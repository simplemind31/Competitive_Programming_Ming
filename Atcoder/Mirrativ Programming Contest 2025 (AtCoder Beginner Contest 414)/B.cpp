#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char c;
ll n,l;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> c >> l;
        if(l+s.size()>100){
            cout << "Too Long";
            return 0;
        }
        s.append(string(l,c));
    }
    cout << s;
}