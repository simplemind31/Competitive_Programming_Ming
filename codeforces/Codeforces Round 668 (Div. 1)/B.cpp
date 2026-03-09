#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t;
string x,y;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> x >> y;
        int x0=0,x1=1e9;
        // si hasta i hay par o impar 1s
        int n=x.size();
        for(int i=0;i<n;i++){
            int con00,con11;
            if(x[i]=='0'){
                if(y[i]=='0'){
                    //hay par cantidad de 1 hasta i
                    con00=min(x0,x1+1);
                    con11=min(x0+2,x1+1);
                }else{
                    //0,1
                    con00=min(x0+1,x1+2);
                    con11=min(x0+1,x1);
                }
            }else{
                if(y[i]=='0'){
                    //1,0
                    con00=min(x0+1,x1);
                    con11=min(x0+1,x1+2);
                }else{
                    //1,1
                    con00=min(x0+2,x1+1);
                    con11=min(x0,x1+1);
                }
            }
            x0=con00;
            x1=con11;
        }
        cout << min(x0,x1) << '\n';
    }
}