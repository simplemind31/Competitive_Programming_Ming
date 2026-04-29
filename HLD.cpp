#include <bits/stdc++.h>
using namespace std;
int main(){
    int x=13;
    int b = 0;
    do{
    // process subset b
        cout << b << ' ';
    }while(b=(b-x)&x);

}