#include <bits/stdc++.h>
using namespace std;
const int n=9,raiz=3;
class Solution{
public:
    int row[n],col[n],blo[n],posi[n][n],todo=(1<<n)-1;
    bool usado[3][n][n];
    void solveSudoku(vector<vector<char>>& board){
        fill(row,row+n,todo);
        fill(col,col+n,todo);
        fill(blo,blo+n,todo);
        fill(&usado[0][0][0],&usado[0][0][0]+3*n*n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.')continue;
                int num=board[i][j]-'1';
                row[i]&=~(1<<num);
                col[j]&=~(1<<num);
                blo[i/raiz*raiz+j/raiz]&=~(1<<num);
                posi[i][j]=1<<num;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.')posi[i][j]=row[i]&col[j]&blo[i/raiz*raiz+j/raiz];
            }
        }
        for(int rondas=0;rondas<n*n;rondas++){
            // si ninguno de cierto rowm col o block puede ser 1 excepto por un numero, entonces usar ese nuemro
            int con[3][n][n];
            fill(&con[0][0][0],&con[0][0][0]+3*n*n,0);
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(int bit=0;bit<n;bit++){
                        if(!(posi[i][j]&(1<<bit)))continue;
                        con[0][i][bit]++;
                        con[1][j][bit]++;
                        con[2][i/raiz*raiz+j/raiz][bit]++;
                    }
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(int bit=0;bit<n;bit++){
                        if(!(posi[i][j]&(1<<bit)))continue;
                        if(con[0][i][bit]==1 || con[1][j][bit]==1 || con[2][i/raiz*raiz+j/raiz][bit]==1){
                            for(int otherbit=0;otherbit<n;otherbit++){
                                if(!(posi[i][j]&(1<<otherbit)) || otherbit==bit)continue;
                                con[0][i][otherbit]--;
                                con[1][j][otherbit]--;
                                con[2][i/raiz*raiz+j/raiz][otherbit]--;
                            }
                            posi[i][j]=1<<bit;
                        }
                    }
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(board[i][j]!='.' || __builtin_popcount(posi[i][j])!=1)continue;
                    board[i][j]=char('1'+__builtin_ctz(posi[i][j]));
                    // quitar los demás
                    for(int k=0;k<n;k++){
                        if(k==j)continue;
                        posi[i][k]&=~posi[i][j];
                    }
                    for(int k=0;k<n;k++){
                        if(k==i)continue;
                        posi[k][j]&=~posi[i][j];
                    }
                    int bloq=i/raiz*raiz+j/raiz;
                    int primx=bloq/raiz*raiz,primy=bloq%raiz*raiz;
                    for(int k=0;k<n;k++){
                        int nuei=primx+k/raiz,nuej=primy+k%raiz;
                        if(nuei==i && nuej==j)continue;
                        posi[nuei][nuej]&=~posi[i][j];
                    }
                }
            }
            // quitar los pares
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(__builtin_popcount(posi[i][j])!=2)continue;
                    if(!usado[0][i][j]){
                        for(int k=0;k<n;k++){
                            if(k==j || (posi[i][j]^posi[i][k]))continue;
                            // dentro de la fila de i, solo j y k pueden tener esos 2 numeros
                            usado[0][i][j]=usado[0][i][k]=true;
                            for(int l=0;l<n;l++){
                                if(l==j || l==k)continue;
                                posi[i][l]&=~posi[i][j];
                            }
                            break;
                        }
                    }
                    if(!usado[1][i][j]){
                        for(int k=0;k<n;k++){
                            if(k==i || (posi[i][j]^posi[k][j]))continue;
                            // dentro de la columna j, solo i y k pueden tener esos 2 numeros
                            usado[1][i][j]=usado[1][k][j]=true;
                            for(int l=0;l<n;l++){
                                if(l==i || l==k)continue;
                                posi[l][j]&=~posi[i][j];
                            }
                            break;
                        }
                    }
                    if(!usado[2][i][j]){
                        // dentro del mismo bloque que de i,j
                        int bloq=i/raiz*raiz+j/raiz;
                        int primx=bloq/raiz*raiz,primy=bloq%raiz*raiz;
                        for(int k=0;k<n;k++){
                            int nuei=primx+k/raiz;
                            int nuej=primy+k%raiz;
                            if((nuei==i && nuej==j) || (posi[i][j]^posi[nuei][nuej]))continue;
                            usado[2][i][j]=usado[2][nuei][nuej]=true;
                            for(int l=0;l<n;l++){
                                int temi=primx+l/raiz,temj=primy+l%raiz;
                                if((temi==i && temj==j) || (temi==nuei && temj==nuej))continue;
                                posi[temi][temj]&=~posi[i][j];
                            }
                            break;
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << posi[i][j] << ' ';
            }
            cout << '\n';
        }
    }
};