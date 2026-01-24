#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,k,con[100],a;
set<pair<int,int>> box;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i=0;i<n;i++)box.insert({0,i});
    for(int i=0;i<k;i++){
        cin >> a;
        a--;
        if(a==-1)a=box.begin()->second;
        box.erase({con[a],a});
        con[a]++;
        box.insert({con[a],a});
        cout << a+1 << ' ';
    }
}