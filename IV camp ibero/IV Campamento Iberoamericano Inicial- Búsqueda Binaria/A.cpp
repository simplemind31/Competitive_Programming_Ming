#include <bits/stdc++.h>
using namespace std;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
    int l=1,r=1e9;
    while(l<r){
        int mid=(l+r)>>1;
        cout << "? " << mid << '\n';
        cout.flush();
        cin >> st;
        if(st=="YES"){
            l=mid+1;
        }else{
            r=mid;
        }
    }
    cout << "! " << l;
}