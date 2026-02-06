#include <bits/stdc++.h>
using namespace std;
int suma,n,m,a;
bitset<1000> exis,nue;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    exis[0]=true;
    while(n--){
        cin >> a;
        a%=m;
        for(int i=m;i>=0;i--){
            if(exis[(i-a+m)%m]){
                nue[i]=true;
                nue[(i-a+m)%m]=true;
            }
        }
        exis=nue;
        nue=0;
        if(exis[m]){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}