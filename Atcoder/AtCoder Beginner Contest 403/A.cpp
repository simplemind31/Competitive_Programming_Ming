#include <bits/stdc++.h>
using namespace std;
int sum,a,n;
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a;
        sum+=(i&1)?a:0;
    }
    cout << sum;
}