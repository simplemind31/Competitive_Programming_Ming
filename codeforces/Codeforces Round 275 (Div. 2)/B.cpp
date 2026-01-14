#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool xd;
ll c1,c2,x,y,l=1,r=1e10,mid,amb,divx,divy,needx,needy,lib;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c1 >> c2 >> x >> y;
    while(l<r){
        mid=(l+r)>>1;amb=mid/(x*y);divx=mid/x-amb;divy=mid/y-amb;needx=c1-divy,needy=c2-divx,lib=mid-amb-divx-divy;
        xd=false;
        if(needx<=0 && needy<=0)xd=true;
        else if(needx<=0){if(needy-lib<=0)xd=true;}
        else if(needy<=0){if(needx-lib<=0)xd=true;}
        else if(needx+needy-lib<=0){xd=true;}
        if(xd)r=mid;
        else l=mid+1;
    }
    cout << l;
}