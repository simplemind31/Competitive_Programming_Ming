#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
const double G=9.8;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //char mat[100][100];
    double angulosexa=45,v=20;
    double angulorad=2*M_PI/360*angulosexa;
    double vx=v*cos(angulorad);
    double vy=v*sin(angulorad);
    double tasc=vy/G;
    double Hmax=vy*vy/(2*G);
    double R=vx*2*tasc;
    //cout << Hmax << ' ' << R << '\n';
    char mat[(int)Hmax+10][(int)R+10];
    for(int i=0;i<(int)(Hmax+10);i++){
        for(int j=0;j<(int)(R+10);j++){
            mat[i][j]=' ';
        }
    }
    //cout << tasc;
    for(double t=0;t<=(2*tasc);t+=0.01){
        //cout << ((2*vy-G*t)*t/2) << ' ' << vx*t << '\n';
        system("cls");
        mat[(int)((2*vy-G*t)*t/2)][(int)(vx*t)]='*';
        for(int i=Hmax;i>=0;i--){
            for(int j=0;j<(int)R+1;j++){
                cout << mat[i][j] << ' ';
            }
            cout << endl;
        }
        Sleep(1);
    }
    /*for(int i=Hmax;i>=0;i--){
        for(int j=0;j<(int)R+1;j++){
            cout << mat[i][j] << ' ';
        }
        cout << '\n';
    }*/
}
