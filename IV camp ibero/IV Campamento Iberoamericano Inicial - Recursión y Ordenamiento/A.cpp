#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll L,A,con,res,ini;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(++con){
        res=0;
        cin >> A >> L;
        ini=A;
        if(A<0 && L<0)break;
        while(A<=L && A>1){
            if(A%2==0)A/=2;
            else A=A*3+1;
            res++;
        }
        if(A==1)res++;
        cout << "Case " << con << ": A = " << ini << ", limit = " << L << ", number of terms = " << res << '\n';
    }
}