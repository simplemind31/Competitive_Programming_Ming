#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ahorr,now,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=1;i<=12;i++){
        cin >> a;
        now+=300-a;
        if(now<0){
            cout << -i;
            return 0;
        }
        ahorr+=now/100;
        now%=100;
    }
    cout << now+ahorr*120;
    
}