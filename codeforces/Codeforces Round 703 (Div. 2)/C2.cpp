#include <bits/stdc++.h>
#define LsOne(x) x&(-x)
using namespace std;
typedef long long ll;
int n,last,now1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int l=1,r=n;
    cout << "? " << 1 << ' ' << n << '\n';
    cout.flush();
    cin >> last;
    bool xd=false;
    if(last!=1){
        cout << "? " << 1 << ' ' << last << '\n';
        cout.flush();
        cin >> now1;
        xd=now1==last;
    }
    if(xd){
        // a la iz
        r=last-1;
        while(l<r){
            int mid=(l+r+1)>>1;
            cout << "? " << mid << ' ' << last << '\n';
            cout.flush();
            cin >> now1;
            if(now1==last)l=mid;
            else r=mid-1;
        }
    }else{
        // a la de
        l=last+1;
        while(l<r){
            int mid=(l+r)>>1;
            cout << "? " << last << ' ' << mid << '\n';
            cout.flush();
            cin >> now1;
            if(now1==last)r=mid;
            else l=mid+1;
        }
    }
    cout << "! " << l << '\n';
    cout.flush();
}