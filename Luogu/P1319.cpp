#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
bool xd;
int n,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int i=0,j=0;
    while(i!=n || j!=0){
        cin >> a;
        while(a--){
            cout << xd;
            j++;
            if(j==n){
                i++;
                j=0;
                cout << '\n';
            }
        }
        xd=!xd;
    }
}