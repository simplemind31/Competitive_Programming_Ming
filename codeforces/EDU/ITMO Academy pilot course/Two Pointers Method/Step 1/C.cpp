#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,i,j;
ll sum=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    int a[n],b[m],res[m];
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<m;i++)cin >> b[i];
    int j=0;
    for(int i=0;i<m;i++){
        if(i && b[i]==b[i-1]){
            res[i]=res[i-1];
            continue;
        }
        while(j<n && a[j]<b[i])j++;
        int con=0;
        while(j<n && a[j]==b[i]){
            j++;
            con++;
        }
        res[i]=con;
    }
    for(int i=0;i<m;i++)sum+=res[i];
    cout << sum;
}