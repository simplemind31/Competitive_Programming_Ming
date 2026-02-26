#include <iostream>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    if(a>b){
        cout << "a es mayor " << a;
    }else{
        if(a==b){
            cout << "a y b son iguales";
        }else{
            cout << "b es mayor " << b;
        }
    }
}