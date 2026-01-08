#include <bits/stdc++.h>
using namespace std;
int t,n,con;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        con=0;
        cin >> st;
        for(char u:st){
            if(u=='Y')con++;
            if(con==2)break;
        }
        if(con==2)cout << "NO\n";
        else cout << "YES\n";
    }
}