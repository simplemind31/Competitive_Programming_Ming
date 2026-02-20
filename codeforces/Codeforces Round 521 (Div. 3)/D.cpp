#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,k,con[200000],a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a;
        con[--a]++;
    }
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)>>1;
        int can=0;
        for(int i=0;i<2e5;i++){
            can+=con[i]/mid;
        }
        if(can>=k)l=mid;
        else r=mid-1;
    }
    for(int i=0;i<2e5 && k;i++){
        int can=con[i]/l;
        while(can-- && k){
            k--;
            cout << i+1 << ' ';
        }
    }
}