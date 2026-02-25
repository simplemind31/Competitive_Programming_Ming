#include <iostream>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a<=0 || b<=0 || c<=0 || a+b<=c || a+c<=b || b+c<=a){
        cout << "No es triangulo";
    }else{
        cout << "Triangulo ";
        if(a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a){
            cout << "Rectangulo ";
        }else if(a*a+b*b>c*c && a*a+c*c>b*b && c*c+b*b>a*a){
            cout << "Acutangulo ";
        }else{
            cout << "Obtusangulo ";
        }

        if(a==b && a==c){
            cout << "Equilatero";
        }else if(a==b || a==c || b==c){
            cout << "Isosceles ";
        }else{
            cout << "Escaleno ";
        }
    }
}