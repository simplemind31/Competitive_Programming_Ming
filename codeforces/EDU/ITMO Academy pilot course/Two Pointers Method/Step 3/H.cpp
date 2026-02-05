#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,s,A,B;
ll maxi=0,cost,wei;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> s >> A >> B;
    int a[n],b[m];
    b[m]=a[n]=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int j=0;j<m;j++){
        cin >> b[j];
    }
    // use puro a;
    sort(a,a+n);
    sort(b,b+m);
    reverse(a,a+n);
    reverse(b,b+m);
    int i=0;
    while(i<n){
        cost+=a[i++];
        wei+=A;
        if(wei>s)break;
        maxi=max(maxi,cost);
    }
    i--;
    for(int j=0;j<m;j++){
        cost+=b[j];
        wei+=B;
        while(wei>s && i>=0){
            wei-=A;
            cost-=a[i--];
        }
        if(wei>s)break;
        maxi=max(maxi,cost);
    }
    cout << maxi;
}