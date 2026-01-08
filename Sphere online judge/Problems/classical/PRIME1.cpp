#include <bits/stdc++.h>
using namespace std;
int t,a,b,x;
bool xd;
int main(){
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(a<=2 && 2<=b){
            cout << 2 << '\n';
            a=3;
        }
        if(a<=3 && 3<=b){
            cout << 3 << '\n';
            a=4;
        }
        //6i+-1
        for(int i=max(a/6-1,1);i*6-1<=b;i++){
            if(6*i-1>=a && 6*i-1<=b){
                x=6*i-1;
                xd=true;
                for(int j=2;j*j<=x;j++){
                    if(x%j==0){
                        xd=false;
                        break;
                    }
                }
                if(xd){
                    cout << x << '\n';
                }
            }
            if(6*i+1>=a && 6*i+1<=b){
                x=6*i+1;
                xd=true;
                for(int j=2;j*j<=x;j++){
                    if(x%j==0){
                        xd=false;
                        break;
                    }
                }
                if(xd){
                    cout << x << '\n';
                }
            }
        }
        cout << '\n';
    }
}