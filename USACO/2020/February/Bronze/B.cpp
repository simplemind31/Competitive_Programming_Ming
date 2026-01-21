#include <bits/stdc++.h>
using namespace std;
int n,con;
string s,t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("breedflip.in","r",stdin);
    freopen("breedflip.out","w",stdout);
    cin >> n >> s >> t;
    if(s[0]!=t[0])con++;
    for(int i=1;i<=n;i++)if(s[i]!=t[i] && s[i-1]==t[i-1])con++; 
    cout << con;
}