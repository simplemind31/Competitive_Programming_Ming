#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,t,now;
long double a;
bitset<2000001> lamp;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> a >> t;
        for(int i=1;i<=t;i++){
            lamp[i*a]=!lamp[i*a];
        }
    }
    for(int i=1;i<=2000000 && !now;i++)if(lamp[i])now=i;
    cout << now;
}