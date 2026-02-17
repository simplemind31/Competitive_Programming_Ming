#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int w,x,h,q,a,b,c,d,e,f,con,tot;
bool vacio[20][20][20];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> w >> x >> h >> q;
    tot=w*x*h;
    while(q--){
        cin >> a >> b >> c >> d >> e >> f;
        for(int i=a-1;i<d;i++)for(int j=b-1;j<e;j++)for(int k=c-1;k<f;k++){
            if(!vacio[i][j][k])tot--;
            vacio[i][j][k]=true;
        }
    }
    cout << tot;
}