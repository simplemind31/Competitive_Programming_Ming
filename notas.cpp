#include <vector>
#include <string>
#include <iostream>
using namespace std;
int main(){
    vector<string> nombres(5);
    vector<int> notas(5);
    string pregunta;
    int cantidadaprovados=0;
    for(int i=0;i<5;i++){
        cin >> nombres[i];
    }
    for(int i=0;i<5;i++){
        cin >> notas[i];
        if(notas[i]>=51){
            cantidadaprovados++;
        }
    }
    cout << "La cantidad de aprovados son: " << cantidadaprovados << endl;
    cin >> pregunta;
    bool existe=false;
    int posicion=-5;
    for(int i=0;i<5;i++){
        if(nombres[i]==pregunta){
            existe=true;
            posicion=i;
        }
    }
    if(existe){
        cout << "La nota de " << pregunta << " es " << notas[posicion];
    }else{
        cout << "No existe en el registro";
    }
    // A B C D E
    // 5 7 3 4 9
    // D
}