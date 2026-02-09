#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b,day,maxi=8;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=1;i<=7;i++){
        cin >> a >> b;
        if(a+b>maxi){
            maxi=a+b;
            day=i;
        }
    }
    cout << day;
}