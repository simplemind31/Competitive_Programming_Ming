#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
using namespace std;
int n,con=1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(con<10)cout << 0;
            cout << con++;
        }
        cout << '\n';
    }
}