#include <bits/stdc++.h>
using namespace std;
bool xd;
char c;
int t,n,m,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        con=xd=0;
        bool mapa[n][m];
        vector<int> sumrow(n),sumcol(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> c;
                mapa[i][j]=(c=='A');
                con+=mapa[i][j];
                sumrow[i]+=mapa[i][j];
                sumcol[j]+=mapa[i][j];
                xd|=(sumrow[i]==m)||(sumcol[j]==n);
            }
        }
        if(con==0)cout << "MORTAL\n";
        else if(con==n*m)cout << "0\n";
        else if(sumrow[0]==m||sumrow[n-1]==m||sumcol[0]==n||sumcol[m-1]==n)cout << "1\n";
        else if(mapa[0][0]||mapa[n-1][0]||mapa[0][m-1]||mapa[n-1][m-1]||xd)cout << "2\n";
        else if(sumrow[0]||sumrow[n-1]||sumcol[0]||sumcol[m-1])cout << "3\n";
        else cout << "4\n";
    }
}