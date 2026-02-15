#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,k,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        ll suma=0;
        priority_queue<int> posi;
        //en posiciones n-(k+1),n-2*(k+1),n-3*(k+1)
        for(int i=0;i<n;i++){
            cin >> a;
            posi.push(a);
            if((n-i)%(k+1)==0){
                suma+=posi.top();
                posi.pop();
            }
        }
        cout << suma << '\n';
    }
}