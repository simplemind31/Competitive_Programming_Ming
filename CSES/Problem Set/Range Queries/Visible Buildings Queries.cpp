#include <bits/stdc++.h>
using namespace std;
int n,q,a,b;
stack<int> cola;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    int nums[n+1],bj[n+1][20];
    for(int i=0;i<n;i++)cin >> nums[i];
    nums[n]=1e9+1;
    bj[n][0]=n;
    cola.push(n);
    for(int i=n-1;i>=0;i--){
        while(nums[i]>=nums[cola.top()])cola.pop();
        bj[i][0]=cola.top();
        cola.push(i);
    }
    for(int i=1;i<20;i++){
        for(int j=0;j<=n;j++){
            bj[j][i]=bj[bj[j][i-1]][i-1];
        }
    }
    while(q--){
        cin >> a >> b;
        a--;b--;
        int res=0;
        for(int i=19;i>=0;i--){
            if(bj[a][i]>b)continue;
            res+=1<<i;
            a=bj[a][i];
        }
        cout << res+1 << '\n';
    }
}