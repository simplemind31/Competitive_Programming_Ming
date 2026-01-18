#include <bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int nums[n],suma=0;
        for(int i=0;i<n;i++){
            cin >> nums[i];
            suma+=nums[i];
        }
        if(suma==0){
            cout << 0 << '\n';
            continue;
        }
        int mini=1e9;
        for(int i=1;i*i<=suma;i++){
            if(suma%i==0){
                //minimu make i
                int now=0,con=0;
                for(int j=0;j<n && con<1e9;j++){
                    now+=nums[j];
                    con++;
                    if(now>i)con=1e9;
                    else if(now==i){
                        now=0;
                        con--;
                    }
                }
                mini=min(mini,con);
                now=0,con=0;
                for(int j=0;j<n && con<1e9;j++){
                    now+=nums[j];
                    con++;
                    if(now>suma/i)con=1e9;
                    else if(now==suma/i){
                        now=0;
                        con--;
                    }
                }
                mini=min(mini,con);
            }
        }
        cout << mini << '\n';
    }
}