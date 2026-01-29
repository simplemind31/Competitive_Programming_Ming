#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,x,y,l,r=1e9;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> x >> y;
    if(n==1){
        cout << min(x,y);
        return 0;
    }
    n--;
    while(l<r){
        int mid=(l+r)>>1;
        if((int)(mid/x)+(int)(mid/y)>=n)r=mid;
        else l=mid+1;
    }
    cout << l+min(x,y);
}