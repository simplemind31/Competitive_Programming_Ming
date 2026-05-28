#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,m;
char mat[2005][2005];
void merge(pair<pair<int,int>,int>& a,pair<pair<int,int>,int> b){
    a.second+=b.second;
    a.first.first=min(a.first.first,b.first.first);
    a.first.second=max(a.first.second,b.first.second);
}
pair<pair<int,int>,int> fill(int x,int y){
    if(x<0 || y<0 || x>=n || y>=m || mat[x][y]=='.')return {{1e9,-1e9},0};
    pair<pair<int,int>,int> res={{y,y},mat[x][y]-'0'};
    mat[x][y]='.';
    merge(res,fill(x-1,y));
    merge(res,fill(x+1,y));
    merge(res,fill(x,y-1));
    merge(res,fill(x,y+1));
    return res;
}
int oils[2005][2005],dp[2005][2005],cubre[2005][2005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin >> mat[i][j];
    vector<pair<pair<int,int>,int>> rango;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='.')continue;
            rango.push_back(fill(i,j));
            oils[rango.back().first.first][rango.back().first.second]+=rango.back().second;
        }
    }
    n=rango.size();
    sort(ALL(rango));
    //for(auto u:rango)cout << u.first.first << ' ' << u.first.second <<' ' << u.second << '\n';
    // n/2=1+2+3+..+x
    //x*(x+1)/2=n/2
    // x*(x+1)=n
    //x^2+x-n=0
    // x=(-1+sqrt(1+4*n))/2~=(-1+2sqrt(n))/2~=sqrt(n)/2
    // hay a lo mucho nsqrt(n)/2 rangos

    // la suma de tamaño de los rangos es a lo mucho m^2
    // cubre[i][j]= i<j,rangos que cubren a i y a j al mismo tiempo
    for(auto u:rango){
        for(int i=u.first.first;i<=u.first.second;i++){
            for(int j=i;j<=u.first.second;j++){
                cubre[i][j]+=u.second;
            }
        }
    }
    // dp[i][j]=maxima cantidad de oils que consigo si el tubo j lo puse en la posicion i
    // caso base j=0 para todo i
    int maxi=0;
    for(int i=0;i<m;i++){
        // que pasa si pongo el primer tubo en esta posicion
        dp[i][0]=cubre[i][i];
        maxi=max(maxi,dp[i][0]);
    }
    cout << maxi << '\n';
    for(int j=1;j<m;j++){
        maxi=0;
        for(int i=m-1;i>=0;i--){
            // =max(dp[a][j-1]+rangos que cubren a i desde a-1)
            // dp[i][j]=max(dp[a][j-1]+rangos que curben a i-rangos que curben a a y a i al mismo tiempo) para a>i
            for(int a=i+1;a<m;a++){
                dp[i][j]=max(dp[i][j],dp[a][j-1]+cubre[i][i]-cubre[i][a]);
            }
            maxi=max(maxi,dp[i][j]);
        }
        cout << maxi << '\n';
    }
}