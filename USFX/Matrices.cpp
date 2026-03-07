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
matriz matriz_magica(int n){
    matriz mat(n,vector<int>(n));
    vector<pair<int,int>> pos(n*n);
    mat[0][n/2]=1;
    pos[0]={0,n/2};
    for(int i=0;i<n*n-1;i++){
        if(pos[i].first==0 && pos[i].second!=n-1){
            pos[i+1]={n-1,pos[i].second+1};
        }else if(pos[i].second==n-1 && pos[i].first!=0){
            pos[i+1]={pos[i].first-1,0};
        }else if(pos[i].first==0){
            pos[i+1]={pos[i].first+1,pos[i].second};
        }else{
            if(pos[i].first-1>=0 && pos[i].second+1<n && mat[pos[i].first-1][pos[i].second+1]==0)pos[i+1]={pos[i].first-1,pos[i].second+1};
            else pos[i+1]={pos[i].first+1,pos[i].second};
        }
        mat[pos[i+1].first][pos[i+1].second]=i+2;
    }
    return mat;
}
void imprimir(matriz x){
    int m=x.size(),n=x[0].size();
    for(int i=0;i<m;i++){
        cout << "|";
        bool xd=false;
        for(int j=0;j<n;j++){
            if(xd)cout << ' ';
            cout << x[i][j];
            xd=true;
        }
        cout << "|\n";
    }
}
matriz X={{0,1},{1,0}};
matriz NOT(matriz x){
    return X*x;
}
int main(){
    int n,m;
    cin >> n >> m;
    matriz ket=obtener(n,m);
    imprimir(NOT(ket));
}