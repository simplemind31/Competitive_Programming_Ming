#include <bits/stdc++.h>
using namespace std;
const int TAMN=100;
const int TAMM=100;
const int limiteinferior=-50;
const int limitesuperior=50;
double f(double x){return x;}
int main(){
    char mat[TAMN][TAMM];
    for(int i=0;i<TAMN;i++){
        for(int j=0;j<TAMM;j++){
            mat[i][j]=' ';
        }
    }
    for(double i=limiteinferior;i<=limitesuperior;i+=0.01){
        double x=i;
        double y=f(x);
        x*=10;
        y*=10;
        if(int(TAMN/2)-int(y)<0 || int(TAMN/2)-int(y)>=TAMN)continue;
        if(int(TAMM/2)+int(x)<0 || int(TAMM/2)+int(x)>=TAMM)continue;
        mat[int(TAMN/2)-int(y)][int(TAMM/2)+int(x)]='*';
    }
    for(int i=0;i<TAMN;i++){
        for(int j=0;j<TAMM;j++){
            cout << mat[i][j];
        }
        cout << endl;
    }
}
