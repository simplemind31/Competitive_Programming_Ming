#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
    scanf("%d %d %d",&a,&b,&c);
    printf("%d",max((b==0)?0:(a-(c-1)/b-1),0));
}