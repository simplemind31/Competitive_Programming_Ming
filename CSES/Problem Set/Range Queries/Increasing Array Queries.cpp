#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    ll nums[n+2],psum[n+2]={0},pad[n+2][20],res[n+2][20];
    for(int i=1;i<=n;i++){
        cin >> nums[i];
        psum[i]=psum[i-1]+nums[i];
    }
    pad[n+1][0]=n+1;
    res[n+1][0]=0;
    nums[n+1]=1e9+1;
    psum[n+1]=psum[n]+nums[n+1];
    stack<int> cola;
    cola.push(n+1);
    for(int i=n;i>0;i--){
        while(nums[cola.top()]<=nums[i])cola.pop();
        pad[i][0]=cola.top();
        res[i][0]=(pad[i][0]-1-i+1)*nums[i]-(psum[pad[i][0]-1]-psum[i-1]);
        cola.push(i);
    }
    for(int j=1;j<20;j++){
        for(int i=1;i<=n+1;i++){
            pad[i][j]=pad[pad[i][j-1]][j-1];
            res[i][j]=res[i][j-1]+res[pad[i][j-1]][j-1];
        }
    }
    while(q--){
        cin >> a >> b;
        ll resp=0;
        for(int j=19;j>=0;j--){
            if(pad[a][j]>b)continue;
            resp+=res[a][j];
            a=pad[a][j];
        }
        resp+=(b-a+1)*nums[a]-(psum[b]-psum[a-1]);
        cout << resp << '\n';
    }
}