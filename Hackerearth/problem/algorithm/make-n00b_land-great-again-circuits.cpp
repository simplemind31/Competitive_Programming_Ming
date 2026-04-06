#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int n,m,q,a;
vector<int> pad,dist;
vector<int> lo,hi;
vector<ll> target;
vector<vector<int>> owns;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    pad.resize(n);
    dist.resize(n);
    owns.resize(m);
    target.resize(m);
    for(int i=1;i<n;i++){
        cin >> pad[i];
        dist[i]=dist[--pad[i]]+1;
    }
    for(int i=0;i<n;i++){
        cin >> a;
        owns[--a].push_back(i);
    }
    for(int i=0;i<m;i++)cin >> target[i];
    lo.resize(m);
    hi.assign(m,q);
    while(true){

    }
}