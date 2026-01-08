#include <bits/stdc++.h>
using namespace std;
int t,n,a,maxi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        maxi=0;
        cin >> n;
        vector<int> conta(n+1),fina(n+1);
        for(int i=0;i<n;i++){
            cin >> a;
            if(a<=n){
                conta[a]++;
            }
        }
        for(int i=1;i<=n;i++){
            if(conta[i]){
                for(int j=i;j<=n;j+=i){
                    maxi=max(maxi,fina[j]=fina[j]+conta[i]);
                }
            }
        }
        cout << maxi << '\n';
    }
}