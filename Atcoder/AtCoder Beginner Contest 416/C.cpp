#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,x;
string now,st[10];
vector<string> ord;
void solve(int pos){
    if(pos==k){
        ord.push_back(now);
        return;
    }
    for(int i=0;i<n;i++){
        string nue=now;
        now+=st[i];
        solve(pos+1);
        now=nue;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k >> x;
    for(int i=0;i<n;i++){
        cin >> st[i];
    }
    solve(0);
    sort(ord.begin(),ord.end());
    cout << ord[x-1];
}