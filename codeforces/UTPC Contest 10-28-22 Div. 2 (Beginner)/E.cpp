#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,now,con;
bitset<100000> usado;
ll res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    priority_queue<int,vector<int>,greater<int>> nums;
    for(int i=0;i<n;i++){
        cin >> a;
        // puedo seleccionar i/2+1;
        if((i&1)==0)nums.push(a);
        else{
            if(a>nums.top()){
                nums.pop();
                nums.push(a);
            }
        }
    }
    while(!nums.empty()){
        res+=nums.top();
        nums.pop();
    }
    cout << res;
}