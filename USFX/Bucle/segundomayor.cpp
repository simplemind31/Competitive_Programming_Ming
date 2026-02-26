#include <iostream>
using namespace std;
int main(){
    int n,a,mayor=0,segundomayor=0,canseg=0,canmay=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        if(a>mayor){
            segundomayor=mayor;
            canseg=canmay;
            mayor=a;
            canmay=1;
        }else if(a==mayor){
            canmay++;
        }else if(a>segundomayor){
            segundomayor=a;
            canseg=1;
        }else if(a==segundomayor){
            canseg++;
        }
    }
    if(canseg==0){
        cout << "No existe segundo mayor\n";
    }else{
        cout << "Existe " << canseg << " segundo mayor, que es el numero " << segundomayor << '\n';
    }
}