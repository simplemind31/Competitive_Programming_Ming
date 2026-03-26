#include <bits/stdc++.h>
using namespace std;
const int limiteiz=-10,limitede=10,limitey2=limiteiz*limiteiz*limitede;
char mat[limitey2+1][limitede*2+1];
int main(){
    for(int i=0;i<=limitey2;i++){
        for(int j=0;j<=2*limitede;j++)mat[i][j]=' ';
    }
    for(int i=limiteiz;i<=limitede;i++){
        int x=i+limitede,y=i*i*i;
        y=limitey2-y;
        mat[y][x]='*';
    }
    for(int i=0;i<=limitey2;i++){
        for(int j=0;j<=2*limitede;j++){
            cout << mat[i][j];
        }
        cout << '\n';
    }
}