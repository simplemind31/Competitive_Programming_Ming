#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        if(c>=a){
            cout << "1\n";
            continue;
        }else if(c*2<=(a+b)){
            cout << "2\n";
            continue;
        }
        ll res1=0,val=0;
        if(abs(c-a)<=abs(c-(a+b))){
            res1=1;
            val=abs(c-a);
        }else{
            res1=2;
            val=abs(c-(a+b));
        }
        //((a+b)*x+a)/(2x+1)
        //(a+b)*x+a<=(2*x+1)*c

        //ax+bx+a<=2cx+c
        //(a+b-2c)x<=c-a
        // a-c<=(2*c-a-b)x
        // (a-c)/(2*c-a-b)<=x
        // menor x posible para que sea minimo
        ll op1=(a-c)/(2*c-a-b);
        ll op2=op1+1;
        //cout << op1 << ' ' << op2 << ' ';
        if((2*op2+1)*abs(c*(2*op1+1)-(op1*(a+b)+a))<=(2*op1+1)*abs(c*(2*op2+1)-(op2*(a+b)+a))){
            // mejor op1
            if(abs(c*(2*op1+1)-(op1*(a+b)+a))<=val*(2*op1+1))cout << 2*op1+1 << '\n';
            else cout << res1 << '\n';
        }else{
            if(abs(c*(2*op2+1)-(op2*(a+b)+a))<=val*(2*op2+1))cout << 2*op2+1 << '\n';
            else cout << res1 << '\n';
        }
    }
}