#include <bits/stdc++.h>
using namespace std;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    for(auto u:st){
        if(u>='a' && u<='z')cout << char(u-'a'+'A');
        else cout << u;
    }
}
