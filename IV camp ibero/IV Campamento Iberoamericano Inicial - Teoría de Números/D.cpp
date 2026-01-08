#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n;
ll a,b;
bitset<1000001> criba;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    criba[0]=criba[1]=1;
    for(int i=4;i<=1e6;i+=2)criba[i]=1;
    for(int i=3;i<=1e3;i+=2){
        if(!criba[i]){
            for(int j=i+i;j<=1e6;j+=i){
                criba[j]=1;
            }
        }
    }
    cin >> n;
    while(n--){
        cin >> a;
        b=sqrt(a);
        if(b*b==a && !criba[b])cout << "YES\n";
        else cout << "NO\n";
    }

}