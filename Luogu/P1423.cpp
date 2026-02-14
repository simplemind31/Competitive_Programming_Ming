#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int l,r=1e9;
double s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> s;
    while(l<r){
        int mid=(l+r)>>1;
        if(2*(powl(98.0/100,mid)-1)/(98.0/100-1)>=s)r=mid;
        else l=mid+1;
    }
    cout << l;
}