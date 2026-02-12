#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
using namespace std;
int k,suma,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> k;
    for(int i=2;suma+i<=k;i++){
        bool xd=true;
        for(int j=2;j*j<=i && xd;j++)if(i%j==0)xd=false;
        if(xd){
            cout << i << '\n';
            suma+=i;
            con++;
        }
    }
    cout << con;
}