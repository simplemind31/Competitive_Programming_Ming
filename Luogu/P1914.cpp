#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> st;
    for(auto u:st){
        cout << char((u+n-'a')%26+'a');
    }
}