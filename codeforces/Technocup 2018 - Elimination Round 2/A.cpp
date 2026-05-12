#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,x;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    vector<bool> a(10),b(10);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> x;
        a[x]=true;
    }
    for(int j=0;j<m;j++){
        cin >> x;
        b[x]=true;
    }
    for(int i=0;i<10;i++){
        if(a[i]&&b[i]){
            cout << i;
            return 0;
        }
    }
    int minia=10,minib=10;
    for(int i=0;i<10 && minia==10;i++){
        if(a[i])minia=i;
    }
    for(int i=0;i<10 && minib==10;i++){
        if(b[i])minib=i;
    }
    cout << min(minia,minib) << max(minia,minib);
}