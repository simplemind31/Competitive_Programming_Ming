#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int a[n-1];
    for(int i=0;i<n-1;i++)cin >> a[i];
    for(int i=0;i<n-1;i++){
        int sum=0;
        for(int j=i;j<n-1;j++){
            sum+=a[j];
            cout << sum << ' ';
        }
        cout << '\n';
    }
}