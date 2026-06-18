#include <bits/stdc++.h>
using namespace std;
int a,b,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(3);
    while(cin >> a >> b){
        if(!a)return 0;
        cout << "Case " << ++con << ": average length between pages = ";
        int mat[100][100];
        fill(&mat[0][0],&mat[0][0]+100*100,1e9);
        mat[--a][--b]=1;
        while(cin >> a >> b){
            if(!a)break;
            mat[--a][--b]=1;
        }
        for(int k=0;k<100;k++){
            for(int i=0;i<100;i++){
                for(int j=0;j<100;j++){
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }
        int res=0,can=0;
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++){
                if(i==j)continue;
                if(mat[i][j]!=1e9){
                    can++;
                    res+=mat[i][j];
                }
            }
        }
        cout << ((float)res/can) << " clicks\n";
    }
}