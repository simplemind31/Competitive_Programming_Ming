#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int t,n,m,a,maxi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        int maxi=-1e9-7,x,y;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> a;
                if(a>maxi){
                    maxi=a;
                    x=i;
                    y=j;
                }
            }
        }
        cout << max(x+1,n-x)*max(y+1,m-y) << '\n';
    }
}
