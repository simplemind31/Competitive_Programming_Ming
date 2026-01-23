#include <bits/stdc++.h>
using namespace std;
char c;
bitset<100> s[100],t[100],a[100];
int n,mini=1e9,con;
int solve(){
    for(int i=con=0;i<n;i++)for(int j=0;j<n;j++)con+=t[i][j]!=a[i][j];
    return con;
}
void rotate(){
    for(int i=0;i<n;i++)s[i]=a[i];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)a[j][n-i-1]=s[i][j];
}
void sc(bool x){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> c;
            (x?t[i][j]:a[i][j])=(c=='#');
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<2;i++)sc(i);
    for(int i=0;i<4;i++){
        mini=min(mini,i+solve());
        rotate();
    }
    cout << mini;
}