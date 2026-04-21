#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
int n,k,a,ta,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    k--;
    for(int i=0;i<n;i++){
        cin >> a;
        if(i==k)ta=a;
        if(i<k && a>0)con++;
        else if(a>0 && i>=k && a==ta)con++;
        else if (i>=k)break;
    }
    cout << con;
}