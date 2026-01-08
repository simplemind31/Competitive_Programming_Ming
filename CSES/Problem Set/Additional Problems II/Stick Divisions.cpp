#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll suma;
int n,x;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> x >> n;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        cin >> x;
        pq.push(x);
    }
    while(pq.size()>1){
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        suma+=a+b;
        pq.push(a+b);
    }
    cout << suma;
}