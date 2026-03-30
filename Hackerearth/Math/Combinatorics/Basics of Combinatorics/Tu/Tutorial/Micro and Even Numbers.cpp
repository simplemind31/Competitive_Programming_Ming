#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,x,con[2];
ll combi(int a,int b){
    // 6 4
    // 6*5/2!
    // 7,3
    // 7*6*5*4
    if(a<b)return 0;
    ll res=1;
    for(int i=a;i>b;i--)res*=i;
    for(int i=a-b;i>0;i--)res/=i;
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> x;
        con[x&1]++;
    }
    cout << combi(con[0],k);
}