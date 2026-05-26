#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,m,res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    char mat[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }
    int nowx=0,nowy=0;
    bool xd=true;
    while((nowx!=n-1 || nowy!=m-1) && xd){
        xd=false;
        for(int dist=0;dist<=abs(n-1-nowx)+abs(m-1-nowy) && !xd;dist++){
            for(int i=0;i<=dist && !xd;i++){
                if(nowx+i>=n || nowy+dist-i>=m)continue;
                if(mat[nowx+i][nowy+dist-i]=='*'){
                    res++;
                    mat[nowx+i][nowy+dist-i]='.';
                    nowx+=i;
                    nowy+=dist-i;
                    xd=true;
                }
            }
        }
    }
    cout << res;
}