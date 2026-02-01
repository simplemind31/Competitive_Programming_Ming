#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,i,j;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    int a[n],b[m];
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<m;i++)cin >> b[i];
    int j=0;
    for(int i=0;i<m;i++){
        while(j<n && a[j]<b[i])j++;
        cout << j << ' ';
    }
}