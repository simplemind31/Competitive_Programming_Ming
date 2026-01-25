#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    map<int,int> con;
    for(int i=0;i<n;i++){
        cin >> a;
        con[a]++;
    }
    for(int i=0;i<m;i++){
        cin >> a;
        con[a]--;
    }
    for(auto u:con){
        for(int i=0;i<u.second;i++){
            cout << u.first << ' ';
        }
    }
}