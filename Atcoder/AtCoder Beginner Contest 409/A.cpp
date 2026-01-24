#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n;
string s,t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> s >> t;
    for(int i=0;i<n;i++){
        if(s[i]==t[i] && s[i]=='o'){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}