#include <bits/stdc++.h>
using namespace std;
char a,b,c;
int n,posx,posy,power[9];
pair<char,pair<int,int>> mat[25][25];
bitset<20000> visited[25][25],posi,visitedestado;
vector<vector<char>> estado={{'.','.','.'},{'.','.','.'},{'.','.','.'}};
bool check(){
    for(int i=0;i<3;i++){
        if(estado[i][0]+estado[i][2]=='O'+'M' && estado[i][1]=='O')return true;
        if(estado[0][i]+estado[2][i]=='O'+'M' && estado[1][i]=='O')return true;
    }
    if(estado[1][1]!='O')return false;
    if(estado[0][0]+estado[2][2]=='O'+'M' || estado[0][2]+estado[2][0]=='O'+'M')return true;
    return false;
}
void tictac(int corres){
    if(visitedestado[corres])return;
    visitedestado[corres]=true;
    if(check()){
        posi[corres]=true;
        return;
    }
    for(int i=0;i<9;i++){
        if(estado[i/3][i%3]=='.'){
            estado[i/3][i%3]='O';
            tictac(corres+power[i]);
            estado[i/3][i%3]='M';
            tictac(corres+2*power[i]);
            estado[i/3][i%3]='.';
        }
    }
}
vector<pair<int,int>> direcciones={{1,0},{-1,0},{0,1},{0,-1}};
set<int> respuesta;
void fill(int x,int y,int corres){
    if(mat[x][y].first=='#' ||visited[x][y][corres])return;
    visited[x][y][corres]=true;
    bool xd=false;
    if((mat[x][y].first=='O' || mat[x][y].first=='M') && estado[mat[x][y].second.first][mat[x][y].second.second]=='.'){
        xd=true;
        estado[mat[x][y].second.first][mat[x][y].second.second]=mat[x][y].first;
        if(mat[x][y].first=='M')corres+=2*power[mat[x][y].second.first*3+mat[x][y].second.second];
        else corres+=power[mat[x][y].second.first*3+mat[x][y].second.second];
    }
    if(posi[corres]){
        respuesta.insert(corres);
        if(xd){
            estado[mat[x][y].second.first][mat[x][y].second.second]='.';
            if(mat[x][y].first=='M')corres-=2*power[mat[x][y].second.first*3+mat[x][y].second.second];
            else corres-=power[mat[x][y].second.first*3+mat[x][y].second.second];
        }
        return;
    }
    for(auto u:direcciones)fill(x+u.first,y+u.second,corres);
    if(xd){
        estado[mat[x][y].second.first][mat[x][y].second.second]='.';
        if(mat[x][y].first=='M')corres-=2*power[mat[x][y].second.first*3+mat[x][y].second.second];
        else corres-=power[mat[x][y].second.first*3+mat[x][y].second.second];
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    power[0]=1;
    for(int i=1;i<9;i++)power[i]=power[i-1]*3;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a >> b >> c;
            if(a=='B'){
                posx=i;
                posy=j;
            }
            if(a=='B' || a=='.')mat[i][j]={'.',{0,0}};
            else if(a=='#')mat[i][j]={'#',{0,0}};
            else mat[i][j]={a,{b-'0'-1,c-'0'-1}};
        }
    }
    tictac(0);
    fill(posx,posy,0);
    cout << respuesta.size();
}