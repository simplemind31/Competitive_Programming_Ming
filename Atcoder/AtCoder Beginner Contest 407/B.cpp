#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int a,b,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> b;
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            if(i+j>=a || abs(i-j)>=b)con++;
        }
    }
    cout << fixed << setprecision(12) << (long double)con/36;
}