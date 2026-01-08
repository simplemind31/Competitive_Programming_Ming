#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,maxi,segunmaxi,a,res,suma,mini=1e9;
bool usado=false;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a;
        suma+=a;
        if(a>maxi){
            segunmaxi=maxi;
            maxi=a;
        }else{
            segunmaxi=max(segunmaxi,a);
        }
    }
    for(int i=0;i<m;i++){
        cin >> a;
        if(maxi>a){
            cout << -1;
            return 0;
        }
        if(a==maxi){
            usado=true;
        }
        res+=a;
    }
    res+=(suma-maxi)*m;
    if(usado){
        cout << res;
    }else{
        cout << res+maxi-segunmaxi;
    }
}