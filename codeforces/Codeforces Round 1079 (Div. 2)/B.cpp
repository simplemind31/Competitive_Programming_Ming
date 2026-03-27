#include <bits/stdc++.h>
using namespace std;
int n,m,t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int p[n],a[n];
        for(int i=0;i<n;i++){
            cin >> p[i];
        }
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        int po=0;
        bool xd=true;
        for(int i=0;i<n && xd;i++){
            while(po+1<n && p[po]!=a[i])po++;
            if(p[po]!=a[i])xd=false;
        }
        if(xd)cout << "YES\n";
        else cout << "NO\n";
    }
}