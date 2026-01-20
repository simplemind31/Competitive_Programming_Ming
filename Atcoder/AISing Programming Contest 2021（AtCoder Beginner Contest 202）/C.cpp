#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,con[100001],a[100001],b[100001];
ll c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<n;i++)cin >> b[i];
    for(int i=0;i<n;i++){
        cin >> c;
        con[b[c-1]]++;
    }
    for(int i=c=0;i<n;i++)c+=con[a[i]];
    cout << c;
}