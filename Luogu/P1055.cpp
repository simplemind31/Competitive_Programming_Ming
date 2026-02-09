#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char n[10],nue;
int suma;
int main(){
    scanf("%c-%c%c%c-%c%c%c%c%c-%c",&n[0],&n[1],&n[2],&n[3],&n[4],&n[5],&n[6],&n[7],&n[8],&n[9]);
    for(int i=0;i<9;i++){
        suma+=(i+1)*(n[i]-'0');
        suma%=11;
    }
    if(suma==10)nue='X';
    else nue=suma+'0';
    if(nue==n[9])printf("Right");
    else printf("%c-%c%c%c-%c%c%c%c%c-%c",n[0],n[1],n[2],n[3],n[4],n[5],n[6],n[7],n[8],nue);
}