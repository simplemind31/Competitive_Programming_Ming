#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,i,j;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    int a[n],b[m],c[n+m];
    for(int k=0;k<n;k++)cin >> a[k];
    for(int k=0;k<m;k++)cin >> b[k];
    while(i<n && j<m){
        if(a[i]<b[j])c[i+++j]=a[i];
        else c[i+j++]=b[j];
    }
    while(i<n)c[i+++j]=a[i];
    while(j<m)c[i+j++]=b[j];
    for(int k=0;k<n+m;k++)cout << c[k] << ' '; 
}