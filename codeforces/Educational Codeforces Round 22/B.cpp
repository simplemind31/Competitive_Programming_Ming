#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,d;
__int128_t x,y,l,r,maxi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> b >> c >> d;
    x=a,y=b,l=c,r=d;
    vector<__int128_t> unl;
    for(__int128_t i=1;i<=r;i*=x){
        for(__int128_t j=1;j<=r;j*=y){
            if(l<=i+j && i+j<=r){
                unl.push_back(i+j);
            }
        }
    }
    unl.push_back(l-1);
    unl.push_back(r+1);
    sort(unl.begin(),unl.end());
    for(int i=1;i<unl.size();i++){
        maxi=max(maxi,unl[i]-unl[i-1]-1);
    }
    cout << (ll)maxi;
}