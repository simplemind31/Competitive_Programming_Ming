#include <bits/stdc++.h>
using namespace std;
bool col,cor,com;
char ans;
int n,l=1,r,mid;
bool rojo(int x){
    cout << "? " << x << '\n';
    cout.flush();
    cin >> ans;
    return ans=='R';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> r;
    col=rojo(1),cor=rojo(r);
    if(col==cor){
        cout << "! " << r;
        cout.flush();
        return 0;
    }
    while(l+1<r){
        com=rojo(mid=(l+r)>>1);
        if((com==col)!=((mid-l+1)&1))cor=com,r=mid;
        else col=com,l=mid;
    }
    cout << "! " << l;
    cout.flush();
}