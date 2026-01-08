#include <bits/stdc++.h>
using namespace std;
int n,raiz,cant;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    raiz=sqrt(n<<=1);
    while(raiz*raiz+raiz>=n){
        raiz--;
    }
    cant=(n>>=1)-(raiz*(raiz+1)/2);
    if(raiz&1){
        cout << cant << "/" << raiz+2-cant;
    }else{
        cout << raiz+2-cant << "/" << cant;
    }
}