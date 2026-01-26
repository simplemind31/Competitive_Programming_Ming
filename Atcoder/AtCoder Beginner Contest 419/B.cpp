#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int q,mini=101,t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> q;
    priority_queue<int,vector<int>,greater<int>> cola;
    while(q--){
        cin >> t;
        if(t==1){
            cin >> t;
            cola.push(t);
        }else{
            cout << cola.top() << '\n';
            cola.pop();
        }
    }
}