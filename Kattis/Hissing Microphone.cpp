#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    for(int i=1;i<st.size();i++){
        if(st[i]=='s' && st[i-1]=='s'){
            cout << "hiss";
            return 0;
        }
    }
    cout << "no hiss";
}