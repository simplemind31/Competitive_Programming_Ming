#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n;
ll res=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int nums[n],iz[n],de[n];
    stack<int> mono;
    mono.push(-1);
    for(int i=0;i<n;i++){
        cin >> nums[i];
        while(mono.top()!=-1 && nums[mono.top()]>=nums[i])mono.pop();
        iz[i]=mono.top()+1;
        mono.push(i);
    }
    while(!mono.empty())mono.pop();
    mono.push(n);
    for(int i=n-1;i>=0;i--){
        while(mono.top()!=n && nums[mono.top()]>=nums[i])mono.pop();
        de[i]=mono.top()-1;
        mono.push(i);
    }
    for(int i=0;i<n;i++){
        res=max(res,1ll*(de[i]-iz[i]+1)*nums[i]);
    }
    cout << res;
}
/*

*/