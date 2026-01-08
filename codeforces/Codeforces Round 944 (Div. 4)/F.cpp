#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,x,y,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        // n*n<=x<(n+1)*(n+1)
        x=con=0,y=n;
        while(y){
            while(x*x+y*y<(n+1)*(n+1)){
                if(n*n<=x*x+y*y){
                    con++;
                }
                x++;
            }
            x--;
            y--;
        }
        cout << con*4 << '\n';
    }
}