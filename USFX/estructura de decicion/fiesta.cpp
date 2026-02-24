#include <iostream>
using namespace std;
int main(){
    int edad;
    cin >> edad;
    /*if(edad>=18){
        cout << ":)";
    }else{
        cout << "Vaya a su casa";
    }*/
    
    if(edad>18 || edad==18){
        cout << ":)";
    }else{
        cout << "Vaya a su casa";
    }
    
    /*if(edad>17){
        cout << ":)";
    }else{
        cout << "Vaya a su casa";
    }*/
}