#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int a,b,c,con[81],maxi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> b >> c;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            for(int k=1;k<=c;k++){
                con[i+j+k]++;
            }
        }
    }
    for(int i=3;i<=a+b+c;i++){
        if(con[i]>con[maxi])maxi=i;
    }
    cout << maxi;
}