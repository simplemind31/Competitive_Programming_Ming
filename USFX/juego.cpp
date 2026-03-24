#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h> // For _kbhit() and _getch()
using namespace std;
const int TAM=11;
char mapa[TAM+4][TAM+4];
pair<int,int> posicion={TAM,TAM/2+2};
void imprimirmapa(){
    for(int i=0;i<TAM+4;i++){
        for(int j=0;j<TAM+4;j++){
            cout << mapa[i][j];
        }
        cout << endl;
    }
}
void limpiar(){
    for(int i=2;i<=TAM+1;i++){
        for(int j=2;j<=TAM+1;j++){
            mapa[i][j]=' ';
        }
    }
}
void encuadrar(){
    for(int i=0;i<=TAM+3;i++){
        mapa[0][i]=mapa[TAM+2][i]=mapa[i][0]=mapa[i][TAM+2]='#';
        mapa[1][i]=mapa[TAM+3][i]=mapa[i][1]=mapa[i][TAM+3]='#';
    }
    mapa[1][TAM/2+2]=' ';
}
bool vivo(){
    for(int i=0;i<=TAM+3;i++){
        for(int j=0;j<=TAM+3;j++){
            if(mapa[i][j]=='M')return true;
        }
    }
    return false;
}
vector<string> bloque1={
    "***",
    " * "
};
vector<string> bloque2={
    "***",
    "  *"
};
vector<string> bloque3={
    "**",
    "**"
};
vector<string> bloque4={
    "****"
};
int cantidadvida=3,nivel=1;
vector<vector<string>> bloques={bloque1,bloque2,bloque3,bloque4};
int main(){
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    while(cantidadvida>0){
        posicion={TAM,TAM/2+2};
        limpiar();
        encuadrar();
        mapa[posicion.first][posicion.second]='M';
        int segundo=0;
        //int blo=uniform_int_distribution<int>(0,3)(rng); 
        vector<pair<int,pair<int,int>>> cola;
        while(true){
            segundo++;
            system("cls");
            if(_kbhit()){ // Check if a key has been pressed
                char ch=_getch(); // Get the pressed key
                if(ch=='w' && mapa[posicion.first-1][posicion.second]==' ')posicion.first--;
                else if(ch=='a' && mapa[posicion.first][posicion.second-1]==' ')posicion.second--;
                else if(ch=='d'&& mapa[posicion.first][posicion.second+1]==' ')posicion.second++;
                else if(ch=='s' && mapa[posicion.first+1][posicion.second]==' ')posicion.first++;
            }
            limpiar();
            for(int i=0;i<cola.size();i++){
                cola[i].second.first++;
                if(cola[i].second.first==TAM+4){
                    cola.erase(cola.begin()+i);
                    i--;
                    continue;
                }
                if(cola[i].first==0){
                    mapa[cola[i].second.first][cola[i].second.second]='*';
                    mapa[cola[i].second.first][cola[i].second.second+1]='*';
                    mapa[cola[i].second.first+1][cola[i].second.second]='*';
                    mapa[cola[i].second.first][cola[i].second.second-1]='*';
                }else if(cola[i].first==1){
                    mapa[cola[i].second.first][cola[i].second.second]='*';
                    mapa[cola[i].second.first][cola[i].second.second+1]='*';
                    mapa[cola[i].second.first+1][cola[i].second.second+1]='*';
                    mapa[cola[i].second.first][cola[i].second.second-1]='*';
                }
                else if(cola[i].first==2){
                    mapa[cola[i].second.first][cola[i].second.second]='*';
                    mapa[cola[i].second.first+1][cola[i].second.second+1]='*';
                    mapa[cola[i].second.first][cola[i].second.second+1]='*';
                    mapa[cola[i].second.first+1][cola[i].second.second]='*';
                }else if(cola[i].first==3){
                    mapa[cola[i].second.first][cola[i].second.second]='*';
                    mapa[cola[i].second.first][cola[i].second.second+1]='*';
                    mapa[cola[i].second.first][cola[i].second.second+2]='*';
                    mapa[cola[i].second.first][cola[i].second.second-1]='*';
                }
            }
            encuadrar();
            if(mapa[posicion.first][posicion.second]=='*'){
                cantidadvida--;
                system("cls");
                cout << "Tienes " << cantidadvida << " vidas" << endl;
                Sleep(2000);
                break;
            }
            mapa[posicion.first][posicion.second]='M';
            imprimirmapa();
            if(posicion==make_pair(1,TAM/2+2)){
                nivel++;
                system("cls");
                cout << "Nivel N" << nivel << endl;
                Sleep(2000);
                break;
            }
            if(segundo==max(2,5-nivel+1)){
                segundo=0;
                // spawnear un bloque
                int blo=uniform_int_distribution<int>(0,3)(rng); 
                int pos=uniform_int_distribution<int>(2,TAM+1)(rng);
                cola.push_back({blo,{0,pos}});
            }
            Sleep(1000.0/nivel);
        }
    }
    cout << "Perdiste";
    Sleep(10000);
}
