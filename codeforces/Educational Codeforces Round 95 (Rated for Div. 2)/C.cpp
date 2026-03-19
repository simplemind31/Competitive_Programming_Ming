#include <bits/stdc++.h>
using namespace std;
int t,n,a,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        vector<bool> tipo(n);
        for(int i=con=0;i<n;i++){
            cin >> a;
            tipo[i]=a;
        }
        bool yo=false;
        for(int i=0;i<n;i++){
            if(i==n-1){
                if(!yo && tipo[i]==1)con++;
                continue;
            }
            if(yo){
                if(tipo[i+1]==1)i++;
            }else{
                if(tipo[i]==1)con++;
                while(i+1<n && tipo[i+1]==0)i++;
            }
            yo=!yo;
        }
        cout << con << '\n';
    }
}