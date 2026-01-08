#include <bits/stdc++.h>
using namespace std;
int t,n,a[200000],b[200000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=0;i<n;i++){
            cin >> b[i];
        }
        if(a[n-1]!=b[n-1]){
            cout << "NO\n";
            continue;
        }
        int need=b[0];
        bool xd=true;
        for(int i=0;i<n-1;i++){
            if(a[i]==need || need==-1){
                //todo lo anterior complido;
                need=-1;
                if(a[i]!=b[i]){
                    need=a[i]^b[i];
                    a[i]=b[i];
                }
            }else if(need==b[i]){
                //mismo objetivo;
                need=a[i]^b[i];
            }else{
                //no se puede, tengo que cambiar primero al need luego al b[i]
                xd=false;
                break;
            }
        }
        if(need!=-1 && need!=a[n-1]){
            xd=false;
        }
        if(xd){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}