#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
    scanf("%d %d %d",&a,&b,&c);
    int mini=min({a,b,c}),maxi=max({a,b,c});
    int mcd=gcd(mini,maxi);
    printf("%d/%d",mini/mcd,maxi/mcd);
}