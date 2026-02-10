#include <bits/stdc++.h>
using namespace std;
int a,b,c,mini,maxi,medi;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> b >> c >> st;
    mini=min({a,b,c}),maxi=max({a,b,c}),medi=a+b+c-maxi-mini;
    for(int i=0;i<3;i++)cout << ((st[i]=='C')?maxi:(st[i]=='B')?medi:mini) << ' ';
}