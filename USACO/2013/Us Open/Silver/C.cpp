#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,k,a,b,tiempo=1;
char c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("cruise.in","r",stdin);
    freopen("cruise.out","w",stdout);
    cin >> n >> m >> k;
    bool tip[m];
    int move[n][2],combi[n][m];
    memset(combi,0,sizeof(combi));
    for(int i=0;i<n;i++){
        cin >> move[i][0] >> move[i][1];
        move[i][0]--;
        move[i][1]--;
    }
    for(int i=0;i<m;i++){
        cin >> c;
        tip[i]=c=='R';
    }
    int now=0,j=0;
    while(combi[now][j]==0 && k){
        combi[now][j]=tiempo;
        now=move[now][tip[j]];
        j++;
        if(j==m){
            j=0;
            tiempo++;
            k--;
        }
    }
    while(j!=0 && k){
        now=move[now][tip[j++]];
        if(j==m){
            j=0;
            tiempo++;
            k--;
        }
    }
    if(k==0){
        cout << now+1 << '\n';
        return 0;
    }
    // cada tiempo-combi[now][j] se repite
    // vuelvo al now en tiempo-combi[now][j]
    k%=(tiempo-combi[now][j]);
    while(k){
        now=move[now][tip[j++]];
        if(j==m){
            j=0;
            k--;
        }
    }
    cout << now+1;
}