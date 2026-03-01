#include <bits/stdc++.h>
using namespace std;
int t;
string solve(int n,string st){
    int can=count(st.begin(),st.end(),'0');
    if(can>1 && can&1)return "ALICE";
    else return "BOB";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        int n;
        string st;
        cin >> n >> st;
        cout << solve(n,st) << '\n';
    }
}