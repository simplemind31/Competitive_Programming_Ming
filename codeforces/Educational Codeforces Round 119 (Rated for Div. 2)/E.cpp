#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int q,t,x,y,pad[500001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> q;
    for(int i=0;i<=500000;i++){
        pad[i]=i;
    }
    pair<int,int> queries[q];
    for(int i=0;i<q;i++){
        cin >> t;
        if(t==1){
            cin >> queries[i].first;
            queries[i].second=-1;
        }else{
            cin >> queries[i].first >> queries[i].second;
        }
    }
    stack<int> nums;
    for(int i=q-1;i>=0;i--){
        if(queries[i].second==-1){
            nums.push(pad[queries[i].first]);
        }else{
            pad[queries[i].first]=pad[queries[i].second];
        }
    }
    while(!nums.empty()){
        cout << nums.top() << ' ';
        nums.pop();
    }
}