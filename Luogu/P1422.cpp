#include <bits/stdc++.h>
using namespace std;
int a;
double b;
int main(){
    cin >> a;
    if(a>=401){
        b+=(a-400)*0.5663;
        a=400;
    }
    if(a>=151){
        b+=(a-150)*0.4663;
        a=150;
    }
    b+=a*0.4463;
    cout << fixed << setprecision(1) << b;
}