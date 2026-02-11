#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
using namespace std;
int n,x,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> x;
    for(int i=1;i<=n;i++){
        int a=i;
        while(a){
            con+=(a%10)==x;
            a/=10;
        }
    }
    cout << con;
}