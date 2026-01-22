#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,x;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie();
    freopen("race.in","r",stdin);
    freopen("race.out","w",stdout);
    cin >> k >> n;
    while(n--){
        cin >> x;
        if(x*(x+1)/2>=k){
            ll temp=(-1+sqrt(1+4*k))/2;
            while(temp*(temp+1)/2<k)temp++;
            while(temp*(temp+1)/2>=k)temp--;
            cout << temp+1 << '\n';
            continue;
        }
        ll mini=1e18;
        for(int j=x;j<k;j++){
            // j=max?
            // sumar hasta j luego descender
            ll suma=j*(j+1)/2+(x+j-1)*(j-x)/2;
            if(suma<k){
                mini=min(mini,j+j-x+(k-suma-1)/j+1);
            }else{
                if(suma-x<k){
                    mini=min(mini,j+j-x);
                }else{
                    break;
                }
            }
        }
        cout << mini << '\n';
    }
}