#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> matriz;
int p,q,r,s;
matriz obtener(int m,int n){
    matriz C(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> C[i][j];
        }
    }
    return C;
}
matriz operator+(matriz x,matriz y){
    if(x.size()!=y.size() || x[0].size()!=y[0].size()){
        return {{}};
    }
    int m=x.size(),n=x[0].size();
    matriz C(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            C[i][j]=x[i][j]+y[i][j];
        }
    }
    return C;
}
matriz operator*(matriz x,matriz y){
    if(x[0].size()!=y.size()){
        return {{}};
    }
    int m=x.size(),n=y[0].size(),k=x[0].size();
    matriz C(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int l=0;l<k;l++){
                C[i][j]+=x[i][l]*y[l][j];
            }
        }
    }
    return C;
}
void imprimir(matriz x){
    int m=x.size(),n=x[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << x[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main(){
    int n,m;
    cin >> p >> q;
    matriz A=obtener(p,q);
    cin >> r >> s;
    matriz B=obtener(r,s);
    imprimir(A*B);
}