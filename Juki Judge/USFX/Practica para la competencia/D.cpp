#include <bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
typedef long long ll;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(1){
        cin >> st;
        if(st[0]=='-' || st[0]=='0')continue;
        reverse(ALL(st));
        st.pop_back();
        while(!st.empty() && st.back()=='0')st.pop_back();
        if(st.empty())st.push_back('0');
        reverse(ALL(st));
        cout << st;
        return 0;
    }
}