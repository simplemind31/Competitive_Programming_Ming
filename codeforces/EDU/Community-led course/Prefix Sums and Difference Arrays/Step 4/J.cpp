#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,k,a,psum[1000001],con;
bitset<1000001> exis;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        cin >> a;
        exis[a]=1;
    }
    for(int i=1;i<=1000000;i++){
        psum[i]=psum[i-1]+exis[i];
        if(i-k>=0){
            if(k-(psum[i]-psum[i-k])<=m)con++;
        }
    }
    cout << con;
}