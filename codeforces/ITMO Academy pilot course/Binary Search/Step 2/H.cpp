#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n[3],p[3],con[3];
ll l,r=1e13,ru;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    for(auto u:st){
        if(u=='B')con[0]++;
        else if(u=='S')con[1]++;
        else con[2]++;
    }
    for(int i=0;i<3;i++)cin >> n[i];
    for(int i=0;i<3;i++)cin >> p[i];
    cin >> ru;
    while(l<r){
        ll mid=(l+r+1)>>1;
        ll mone=0;
        for(int i=0;i<3;i++)mone+=max(0ll,mid*con[i]-n[i])*p[i];
        if(mone<=ru)l=mid;
        else r=mid-1;
    }
    cout << l;
}