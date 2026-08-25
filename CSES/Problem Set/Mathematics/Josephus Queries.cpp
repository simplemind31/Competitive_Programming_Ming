#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,q;
int find(int x,int primero,int iesimo){
    int now=(x+primero)/2;
    return (now>=iesimo)?(iesimo-1)*2+!primero:2*find(x-now,primero^(x&1),iesimo-now)+primero;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> q;
    while(q--){
        cin >> n >> k;
        cout << find(n,0,k)+1 << '\n';
    }
}