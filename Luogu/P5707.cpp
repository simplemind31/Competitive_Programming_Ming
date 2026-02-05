#include <bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main(){
    scanf("%d %d",&a,&b);
    printf("%02d:%02d",((1910-(a-1)/b-1)/60)%24,(1910-(a-1)/b-1)%60);
}