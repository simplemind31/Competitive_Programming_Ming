#include <bits/stdc++.h>
using namespace std;
int a,b,x1,y,x2,y2;
int mat[10000][10000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> b >> x1 >> y >> x2 >> y2;
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            if((i+j)%(2*a)==0)mat[i][j]=1;
            if(abs(i-j)%(2*b)==0)mat[i][j]=1;
            cout << mat[i][j];
        }
        cout << endl;
    }
}
/*
a-> cada 2a/
b-> cada 2b\
*/