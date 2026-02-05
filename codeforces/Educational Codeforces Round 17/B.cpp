#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int a,b,c,m,x;
ll cost;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> b >> c >> m;
    vector<int> USB,PS;
    for(int i=0;i<m;i++){
        cin >> x >> st;
        if(st=="USB")USB.push_back(x);
        else PS.push_back(x);
    }
    sort(REV(USB));
    sort(REV(PS));
    while(a && !USB.empty()){
        a--;
        cost+=USB.back();
        USB.pop_back();
    }
    while(b && !PS.empty()){
        b--;
        cost+=PS.back();
        PS.pop_back();
    }
    for(auto u:PS)USB.push_back(u);
    sort(REV(USB));
    while(c && !USB.empty()){
        c--;
        cost+=USB.back();
        USB.pop_back();
    }
    cout << m-USB.size() << ' ' << cost;
}