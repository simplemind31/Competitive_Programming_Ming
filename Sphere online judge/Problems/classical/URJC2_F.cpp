#include<bits/stdc++.h>
using namespace std;
char fac[2000][4000];
int n,longi=3,alt=1,centri=1,centrj=2;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<1000;i++){
        for(int j=0;j<2000;j++){
            fac[i][j]=' ';
        }
    }
    fac[0][0]=fac[0][2]='H';
    fac[0][1]='-';
    cin >> n;
    while(--n){
        for(int i=0;i<alt;i++){
            for(int j=longi+1;j<=2*longi;j++){
                fac[i][j]=fac[i][j-(longi+1)];
            }
        }
        longi=2*longi+1;
        for(int i=alt+1;i<=2*alt;i++){
            for(int j=0;j<longi;j++){
                fac[i][j]=fac[i-(alt+1)][j];
            }
        }
        alt=2*alt+1;
        for(int i=centri;i<(alt-1)/2+1+centri-1;i++){
            fac[i][centrj-1]='|';
            fac[i][(longi-1)/2+1+centrj-1]='|';
        }
        centri=(alt+1)/2;
        for(int j=centrj;j<(longi-1)/2+1+centrj-1;j++){
            fac[centri-1][j]='-';
        }
        centrj=(longi+1)/2;
    }
    bool xd=false;
    for(int i=0;i<alt;i++){
        for(int j=0;j<longi;j++){
            if(i==centri-1){
                if(xd && fac[i][j]==' '){
                    break;
                }
                if(fac[i][j]!=' '){
                    xd=true;
                }
                cout << fac[i][j];
            }else{
                cout << fac[i][j];
            }
        }
        cout << '\n';
    }
}