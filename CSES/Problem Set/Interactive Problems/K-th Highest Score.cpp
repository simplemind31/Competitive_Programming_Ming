#include <bits/stdc++.h>
using namespace std;
int n,k;
int ask(char F,int x){
    if(x<1)return 2e9;
    if(x>n)return 0;
    cout << F << ' ' << x << '\n';
    cout.flush();
    int a;
    cin >> a;
    return a;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    n=min(n,k);
    int l=max(1,k-n),r=n+1,F,S;
    while(l<r){
        int mid=(l+r)>>1;
        F=ask('F',mid),S=ask('S',k-mid);
        if(F<S)r=mid;
        else l=mid+1;
    }
    int res;
    if(l==n+1)res=ask('S',k-n);
    else if((F=ask('F',l))>(S=ask('S',k-l+1)))res=F;
    else res=ask('S',k-(l-1));
    cout << "! " << res;
    cout.flush();
}