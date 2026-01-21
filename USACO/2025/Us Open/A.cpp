#include <bits/stdc++.h>
using namespace std;
bool estado[3000][3000];
char c;
int n,m,a,b,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cin >> c;
            if(c=='W'){
                estado[i][j]=1;
                estado[j][i]=0;
            }else if(c=='L'){
                estado[i][j]=0;
                estado[j][i]=1;
            }else{
                estado[i][j]=estado[j][i]=0;
            }
        }
        cin >> c;
        estado[i][i]=0;
    }
    while(m--){
        cin >> a >> b;
        //cual simbolo gana a a y b?
        a--;b--;
        for(int i=con=0;i<n;i++)if(estado[i][a]&&estado[i][b])con++;
        cout << con+con*(con-1)+2*con*(n-con) << '\n';
    }
}